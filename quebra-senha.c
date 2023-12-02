#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_LOGIN 20
#define MAX_SENHA 32

typedef struct {
  char nome[MAX_NOME];
  char data_nascimento[10];
  char login[MAX_LOGIN];
  char senha_criptografada[64];
  char data_ultima_alteracao[10];
} Usuario;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Uso: %s <arquivo-usuarios> <arquivo-senhas-fracas> <arquivo-relatorio>\n", argv[0]);
    return 1;
  }

  // Abre os arquivos de entrada e saída
  FILE *arquivo_usuarios = fopen(argv[1], "r");
  if (arquivo_usuarios == NULL) {
    printf("Erro ao abrir o arquivo de usuários '%s'.\n", argv[1]);
    return 1;
  }

  FILE *arquivo_senhas_fracas = fopen(argv[2], "r");
  if (arquivo_senhas_fracas == NULL) {
    printf("Erro ao abrir o arquivo de senhas fracas '%s'.\n", argv[2]);
    return 1;
  }

  FILE *arquivo_relatorio = fopen(argv[3], "w");
  if (arquivo_relatorio == NULL) {
    printf("Erro ao abrir o arquivo de relatório '%s'.\n", argv[3]);
    return 1;
  }

  // Inicializa variáveis
  Usuario usuario;
  char senha_fraca[MAX_SENHA];
  unsigned char hash_senha_fraca[SHA256_DIGEST_LENGTH];
  int quebra_senha = 0;

  // Lê o arquivo de usuários
  while (fscanf(arquivo_usuarios, "%[^--]\n", usuario.nome) != EOF) {
    fscanf(arquivo_usuarios, "%[^--]\n", usuario.data_nascimento);
    fscanf(arquivo_usuarios, "%[^--]\n", usuario.login);
    fscanf(arquivo_usuarios, "%s\n", usuario.senha_criptografada);
    fscanf(arquivo_usuarios, "%[^--]\n", usuario.data_ultima_alteracao);

    // Para cada senha fraca
    while (fscanf(arquivo_senhas_fracas, "%s\n", senha_fraca) != EOF) {
      // Calcula o hash da senha fraca
      sha256((unsigned char *)senha_fraca, strlen(senha_fraca), hash_senha_fraca);

      // Compara o hash da senha fraca com o hash da senha criptografada do usuário
      if (memcmp(hash_senha_fraca, usuario.senha_criptografada, SHA256_DIGEST_LENGTH) == 0) {
        // Achou uma quebra de senha
        quebra_senha = 1;

        // Escreve o relatório de quebra
        fprintf(arquivo_relatorio, "%s %s %s %s\n", usuario.login, senha_fraca, usuario.nome, usuario.data_nascimento);
      }
    }

    // Se não houve quebra de senha, escreve um separador no relatório
    if (!quebra_senha) {
      fprintf(arquivo_relatorio, "---\n");
    }

    quebra_senha = 0;
  }

  // Fecha os arquivos
  fclose(arquivo_usuarios);
  fclose(arquivo_senhas_fracas);
  fclose(arquivo_relatorio);

  return 0;
}
