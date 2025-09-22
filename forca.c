#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int letrasChutadas[26]={0};

void lerLetra();
void mostrarGrafico(int erros);

int main() {
    int mode;
    printf("0 = inserir palavra\n");
    printf("1 = times de futebol\n");
    printf("2 = capitais\n");
    printf("3 = animais\n");
    printf("Insira o modo de jogo: ");
    scanf("%d", &mode);

    char palavra[101];

    if (mode == 0) {
        getchar();
        printf("Insira a palavra: ");
        fgets(palavra, 101, stdin);
        palavra[strlen(palavra) - 1] = '\0';
    } else if (mode == 1) {
        srand(time(NULL));
    
        char* times[100] = {
            "Flamengo", "Palmeiras", "Sao Paulo", "Corinthians", "Vasco",
            "Gremio", "Internacional", "Cruzeiro", "Atletico Mineiro", "Botafogo",
            "Fluminense", "Santos", "Bahia", "Fortaleza", "Ceara",
            "Athletico Paranaense", "Goias", "Coritiba", "Avai", "Chapecoense",
            "Bragantino", "Ponte Preta", "Guarani", "America Mineiro", "Nautico",
            "Sport", "Criciuma", "Figueirense", "Vitoria", "ABC",
            "CSA", "CRB", "Sampaio Correa", "Paysandu", "Remo",
            "Operario", "Vila Nova", "Ituano", "Londrina", "Botafogo SP",
            "Novorizontino", "Mirassol", "Juventude", "Cuiaba", "Joinville",
            "Parana", "Portuguesa", "Ypiranga", "Ferroviaria", "Brasiliense",
            "Ipatinga", "Volta Redonda", "Tombense", "Sao Caetano", "XV de Piracicaba",
            "Treze", "Campinense", "Confiança", "Luverdense", "Boa Esporte",
            "Barueri", "Resende", "Macae", "Madureira", "America RN",
            "Anapolina", "Anapolis", "Rio Branco", "Noroeste", "Brusque",
            "Caldense", "Democrata", "Uberlandia", "Aparecidense", "Altos",
            "Floresta", "Manaus", "Ferroviario", "Altamira", "Central",
            "Serra", "Icasa", "Caxias", "Pelotas", "Inter Limeira",
            "Oeste", "Rio Claro", "Tupi", "Metropolitano", "Guaratingueta",
            "Marilia", "Nacional AM", "Moto Club", "Fast Club", "Porto Velho",
            "Penapolense", "Sao Jose", "Botafogo PB", "Horizonte", "Uniao Frederiquense"
        };

        int index = rand() % 100;
        strcpy(palavra, times[index]);
    } else if (mode == 2) {
        srand(time(NULL));
    
        char* capitais[100] = {
            "Brasilia", "Buenos Aires", "Lima", "Bogota", "Caracas",
            "Quito", "Santiago", "Montevideo", "La Paz", "Assuncao",
            "Washington", "Ottawa", "Cidade do Mexico", "Havana", "Kingston",
            "Paris", "Londres", "Berlim", "Roma", "Madrid",
            "Lisboa", "Oslo", "Estocolmo", "Copenhague", "Helsinque",
            "Dublin", "Viena", "Atenas", "Varsovia", "Praga",
            "Bruxelas", "Amsterdam", "Luxemburgo", "Berna", "Budapeste",
            "Moscou", "Pequim", "Toquio", "Seul", "Nova Delhi",
            "Islamabade", "Banguecoque", "Hanoi", "Jacarta", "Manila",
            "Colombo", "Cabul", "Teera", "Bagda", "Riad",
            "Jerusalem", "Ancara", "Astana", "Doha", "Abu Dhabi",
            "Kuala Lumpur", "Cingapura", "Ulan Bator", "Bishkek", "Dusambe",
            "Nairobi", "Pretoria", "Luanda", "Maputo", "Harare",
            "Addis Ababa", "Kampala", "Accra", "Dacar", "Tripoli",
            "Argel", "Cartum", "Tunis", "Abuja", "Bamaco",
            "Bissau", "Freetown", "Monrovia", "Rabat", "Conacri",
            "Djibuti", "Reiquiavique", "Canberra", "Wellington", "Suva",
            "Porto Moresby", "Apia", "Nukualofa", "Male", "Katmandu",
            "Thimphu", "Muscate", "Sana", "Beirute", "Cidade do Vaticano",
            "San Marino", "Andorra la Vella", "Podgorica", "Skopje", "Erevan"
        };

        int index = rand() % 100;
        strcpy(palavra, capitais[index]);
    } else if (mode == 3) {
        srand(time(NULL));
    
        char* animais[100] = {
            "Cachorro", "Gato", "Cavalo", "Vaca", "Porco",
            "Galinha", "Pato", "Ovelha", "Cabra", "Coelho",
            "Rato", "Leao", "Tigre", "Elefante", "Girafa",
            "Zebra", "Macaco", "Urso", "Panda", "Canguru",
            "Hipopotamo", "Rinoceronte", "Avestruz", "Foca", "Morsa",
            "Tartaruga", "Jacare", "Crocodilo", "Cobra", "Lagarto",
            "Iguana", "Arraia", "Tubarao", "Polvo", "Lula",
            "Estrela do mar", "Coral", "Peixe", "Golfinho", "Baleia",
            "Papagaio", "Periquito", "Canario", "Gaviao", "Aguia",
            "Coruja", "Falcao", "Morcego", "Tamandua", "Bicho-preguica",
            "Tatuzinho", "Capivara", "Anta", "Quati", "Lobo",
            "Raposa", "Esquilo", "Ornitorrinco", "Lontra", "Doninha",
            "Camelo", "Dromedario", "Cervo", "Rena", "Alce",
            "Guaxinim", "Paca", "Cutia", "Onca", "Guepardo",
            "Pantera", "Chita", "Hiena", "Urubu", "Condor",
            "Arara", "Tucano", "Beija-flor", "Galo", "Codorna",
            "Marreco", "Sapo", "Ra", "Perereca", "Salamandra",
            "Gamba", "Carneiro", "Bicho-pau", "Louva-deus", "Formiga",
            "Abelha", "Vespa", "Mosca", "Mosquito", "Barata",
            "Escorpiao", "Aranha", "Caranguejo", "Lagosta", "Camarao"
        };

        int index = rand() % 100;
        strcpy(palavra, animais[index]);
    }

    int tamanho = strlen(palavra);
    int finalizado = 0, erros = 0, faltamDescobrir = 0;
    
    int i, j;
    
    for (i = 0; i < tamanho; i++) {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
            palavra[i] = palavra[i] - 'A' + 'a';
        else if ((palavra[i] >= 'a' && palavra[i] <= 'z') || palavra[i] == '-') {
            // Mantém
        }
        else palavra[i] = ' ';
    }
    
    while (!finalizado) {
        printf("\033[2J\033[H");

        if (mode == 1) printf("DICA: times de futebol\n");
        if (mode == 2) printf("DICA: capitais\n");
        if (mode == 3) printf("DICA: animais\n");
        printf("LETRAS: ");
        erros = 0;
        faltamDescobrir = 0;

        for (i = 0; i < 26; i++) {
            if (letrasChutadas[i]) {
                int encontrou = 0;

                for (j = 0; j < tamanho && palavra[j]; j++) {
                    if (palavra[j] == i + 'a') {
                        encontrou = 1;
                        break;
                    }
                }

                printf("%s%c \033[0;0m", !encontrou ? "\033[0;91m" : "\033[0;33m",  i + 'A');

                if (!encontrou) erros++;
            }
        }
        printf("\n\n");

        mostrarGrafico(erros);
        
        for (i = 0; i < tamanho && palavra[i]; i++) {
            if (palavra[i] == '-' || palavra[i] == ' ') printf("%c ", palavra[i]);
            else if (letrasChutadas[palavra[i] - 'a']) printf("\033[0;36m%c \033[0;0m", palavra[i] - 'a' + 'A');
            else {
                faltamDescobrir++;
                printf("\033[0;90m_ \033[0;0m");
            }
        }
        
        printf("\n\n");

        if (faltamDescobrir == 0) {
            printf("\033[0;32mVOCE GANHOU!\033[0;0m");
            finalizado = 1;
        }

        if (erros >= 7) {
            printf("\033[0;31mVOCE PERDEU!\nA PALAVRA ERA: %s\033[0;0m", palavra);
            finalizado = 1;
        }

        lerLetra(letrasChutadas);
    }

    printf("\n");

    return 0;
}

void lerLetra() {
    char temp = getchar();

    if (temp >= 'A' && temp <= 'Z')
        temp = temp - 'A' + 'a';
    else if (temp >= 'a' && temp <= 'z') {
        // Mantém
    }
    else return;

    if (letrasChutadas[temp - 'a'] == 0)
        letrasChutadas[temp - 'a'] = 1;
}

void mostrarGrafico(int erros) {
    printf("\033[0;90m/---\\\033[0;0m\n");
    printf("\033[0;90m|\033[0;31m   %c\033[0;0m\n", erros > 0 ? 'o' : ' ');
    printf("\033[0;90m|\033[0;31m  %c%c%c\033[0;0m\n", erros > 2 ? '/' : ' ', erros > 1 ? '|' : ' ', erros > 3 ? '\\' : ' ');
    printf("\033[0;90m|\033[0;31m  %c %c\033[0;0m\n", erros > 4 ? '/' : ' ', erros > 5 ? '\\' : ' ');
    printf("\033[0;90m|\033[0;0m      ");
}
