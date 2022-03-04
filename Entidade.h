typedef struct _elemento
{
    int chave;
    float valor;
} elemento;

typedef struct _Linha_Hash
{
    elemento vet[10];
    int num_elementos;

} linha_hash;

typedef struct _Tabela_Hash
{
    linha_hash linha[13];

} tab;


void mostrar_tabela ();

void inicializa_tabela ();

int gerar_codigo_hash_linha (int chave);

int gerar_codigo_hash_coluna (int chave);

void inserir ();

elemento* buscar (int chave);

elemento* excluir_elemento (int chave);
