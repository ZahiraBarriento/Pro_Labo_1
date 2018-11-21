
int getInt();
float getFloat();
char getChar();

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(int* input, char requestMessage[],char errorMessage[], int lowLimit, int hiLimit, int attemps);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int lowLimit,int maxLenght,int attemps);
int getValidFloat(float* input, char requestMessage[],char errorMessage[], float lowLimit, float hiLimit, int attemps);
int getValidSexo(char* input, char requestMessage[], int attemps);

void cleanStdin(void);
