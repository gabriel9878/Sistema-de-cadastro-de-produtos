#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes

#define PRDTQ 50
#define ADMQ 5

//ESTRUTURAS

//Estrutura de um produto.
typedef struct {

    char name[25];
    int id;
    float weight;
    int quantity;
    float price;

}   PRODUCT;

//Estrutura de um administrador

typedef struct {

    char name[25];
    char login[15];
    char password[15];
    int id;

}   ADMIN;

typedef struct {

    char name[25];
    char login[15];
    char password[15];

}    EMPLOYEE; 

//Função que imprime a interface do menu na tela.

void showMenuInterface() {
    
    printf("|---------------------------------------------------------------------|\n");
    printf("|                                                                     |\n");
    printf("|------------------------|[xSHOPx|xXx|xSHOPx]|------------------------|\n");
    printf("|                                                                     |\n");
    printf("|---------------------------------------------------------------------|\n\n\n");

    printf("|[1]||  : Search product\n");
    printf("|[2]||  : Search admin\n");
    printf("|[3]||  : Edit product\n");
    printf("|[4]||  : Edit admin\n");
    printf("|[5]||  : Remove product\n");
    printf("|[6]||  : Add product\n");
    printf("|[7]||  : Add admin\n");
    printf("|[8]||  : Show registred products\n");
    printf("|[9]||  : Show registred admins\n");
    printf("|[10]|  : Restock product\n");
    printf("|[11]|  : Close program\n\n");
    printf("Key:");

}

//Fun��o de inteiro que retorna 1 se o numero do produto em quest�o for menor que o contador dos produtos.
int compnumWithcounterPointer(int num,int* counterP) {

    if(num < *counterP) {

        return 1;

    }

    return 0;

}

//Fun��o que remove quebra de linha de uma string.

void removeBrokenLine(char *string) {

    if(string != NULL && strlen(string) > 0) {
        
        short tamanho = strlen(string);

        if(string[tamanho-1] == '\n') {
            
            string[tamanho-1] = '\0';

        }

    }

}

//Funcao que recebe um numero como opcao do usuario

int setNum() {

    int num;

    fflush(stdin);
    scanf("%d",&num);
    printf("\n");

    return num;

}

//funcao que atraves do id descobre o numero do produto no array dos produtos.

int getProdNum(PRODUCT products[],int prodId) {

    int counter;

    for(counter = 0; counter < PRDTQ; counter++) {

        if(prodId == products[counter].id) {

            break;

        }

    }

    return counter;

}

//funcao que atraves do id descobre o numero do admnistrador no array de administradores.

int getAdminNum(ADMIN admins[],int adminId) {

    int counter;

    for(counter = 0; counter < ADMQ; counter++) {

        if(adminId == admins[counter].id) {

            break;

        }

    }

    return counter;

}

//Funcao que imprime os produtos cadastrados do mercado na tela.

void showRegistredProducts(PRODUCT products[]) {

    int counter;

    for(counter=0; counter<PRDTQ; counter++) {

        if(products[counter].id != -1) {

            printf("Product %d\n\n",counter+1);
            printf("Name:%s\n",products[counter].name);
            printf("ID:%i\n\n",products[counter].id);

        }

    }

}

//Funcao que imprime os administradores cadastrados do mercado na tela.

void showRegistredAdmins(ADMIN admins[]) {

    int counter;

    for(counter=0; counter<ADMQ; counter++) {

        if(strncmp(admins[counter].login,"              ",15) == 1) {

            printf("Admin %d\n\n",counter+1);
            printf("Name:%s\n",admins[counter].name);
            printf("ID:%d\n\n",admins[counter].id);

        }  

    }

}

//Imprime na tela a mensagem de fim do programa.

void showEndOfShopMessage(){

    printf("\n\n__________________________|[VOLTE SEMPRE]|____________________________\n");

}

//Imprime na tela a mensagem que pergunta se o usu�rio deseja buscar outro produto.

void menuSearchOtherProductInterface() {

    printf("You want to search other product ?\n\n");
    printf("1-Search other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

void menuSearchOtherAdminInterface() {

    printf("You want to search other admin ?\n\n");
    printf("1-Search other admin\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usu�rio deseja editar outro produto.

void menuEditOtherProductInterface() {

    printf("You want to edit other product ?\n\n");
    printf("1-Edit other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usu�rio deseja editar outro produto.

void menuEditOtherAdminInterface() {

    printf("You want to edit other administrator ?\n\n");
    printf("1-Edit other administrator\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usuario deseja remover outro produto.

void menuRemoveOtherProductInterface() {

    printf("You want to remove other product ?\n\n");
    printf("1-Remove other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usuario deseja restocar outro produto.

void menuRestockOtherProductInterface(){

    printf("You want to restock other product ?\n\n");
    printf("1-Restock other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");


}

//Imprime na tela a mensagem que pergunta se o usuario deseja adicionar outro produto.

void menuAddOtherProductInterface() {

    printf("You want to add other product ?\n\n");
    printf("1-Add other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usuario deseja adicionar outro administrador.

void menuAddOtherAdminInterface() {

    printf("You want to add other administrator ?\n\n");
    printf("1-Add other administrator\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela uma interface que pergunta o que se deseja editar do produto desejado.

void subMenuEditProductInterface() {

    printf("Choose what you want to edit\n");
    printf("1-Name\n");
    printf("2-ID\n");
    printf("3-Weight\n");
    printf("4-Quantity\n");
    printf("5-Price\n");
    printf("6-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela uma interface que pergunta o que se deseja editar do produto desejado.

void subMenuEditAdminInterface() {

    printf("Choose what you want to edit\n");
    printf("1-Name\n");
    printf("2-Login\n");
    printf("3-Password\n");
    printf("4-ID\n");
    printf("5-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela uma interface que pergunta se o usu�rio quer adicionar um produto no slot encontrado.

void subMenuAddProductInterface(int* prodNum) {

    printf("Slot %d is free.You wanna to add a product in this slot?\n\n",(*prodNum) + 1);
    printf("1-Add a new product in this slot\n");
    printf("2-Go to the next slot\n");
    printf("3-Go back to menu\n");
    printf("Key:");

}

void subMenuAddAdminInterface(int* adminNum) {

    printf("Slot %d is free.You wanna to add a admin in this slot?\n\n",(*adminNum) + 1);
    printf("1-Add a new admin in this slot\n");
    printf("2-Go to the next slot\n");
    printf("3-Go back to menu\n");
    printf("Key:");

}

//Imprime na tela uma interface que pergunta se o usu�rio quer adicionar um produto no slot encontrado.

void subMenuRemoveProductInterface() {

    printf("Are you sure you want to remove this product ?\n\n");
    printf("1-Remove product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Funcao que edita o nome de um produto.

void editProductName(PRODUCT products[],int numProd) {

     char tempName[25];
    
    do{

        printf("Type the name of the new product\n");
        printf("Name:");
        fflush(stdin);
        fgets(tempName,25,stdin);
        removeBrokenLine(tempName);
        printf("\n");    
    
    
    if(checkProdNameCad(products,tempName) == 1){

        printf("Name already registred.Try again with a distint name!!!\n\n");
        
    }

    }while(checkProdNameCad(products,tempName) == 1);
    

    return tempName;

}

//Funcao que edita o nome de um administrador.

void editAdminName(ADMIN admins[],int numAdmin) {

    printf("Type the new name of the administrator\n");
    printf("Name:");
    fflush(stdin);
    fgets(admins[numAdmin].name,25,stdin);
    removeBrokenLine(admins[numAdmin].name);
    printf("\n");

}

//Funcao que edita o login de um administrador.

void editAdminLogin(ADMIN admins[],int numAdmin) {
    
    do{

        printf("Type the new login of the administrator\n");
        printf("Login:");
        fflush(stdin);
        fgets(admins[numAdmin].login,15,stdin);
        removeBrokenLine(admins[numAdmin].login);
        printf("\n");    
    
    
    if(checkAdminLoginCad(admins,admins[numAdmin].login) == 1){

        printf("Login already registred.Try again with a distint login!!!\n\n");
        
    }

    }while(checkAdminLoginCad(admins,admins[numAdmin].login) == 1);

}

//Funcao que edita a senha de um administrador.

void editAdminPassword(ADMIN admins[],int numAdmin) {

    printf("Type the new password of the administrator\n");
    printf("Password:");
    fflush(stdin);
    fgets(admins[numAdmin].password,15,stdin);
    removeBrokenLine(admins[numAdmin].password);
    printf("\n");

}

//Funcao que edita o id de um produto.

void editProductID(PRODUCT products[],int numProd) {

    do{

    printf("Type the new id of the product\n");
    printf("ID:");
    fflush(stdin);
    scanf("%d",&products[numProd].id);
    printf("\n");

    if(checkProdIdIsCad(products,products[numProd].id) == 1){

        printf("ID already registred.Try again with a distint id !!!\n\n");
    }

    }while(checkProdIdIsCad(products,products[numProd].id) == 1);

}

//Funcao que edita o id de um administrator.

void editAdminID(ADMIN admins[],int numAdmin) {

    do{

    printf("Type the new id of the administrator\n");
    printf("ID:");
    fflush(stdin);
    scanf("%d",&admins[numAdmin].id);
    printf("\n");

    if(checkProdIdIsCad(admins,admins[numAdmin].id) == 1){

        printf("ID already registred.Try again with a distint id !!!\n\n");
    }

    }while(checkProdIdIsCad(admins,admins[numAdmin].id) == 1);

}

//Fun��o que edita o peso de um produto.

void editProductWeight(PRODUCT products[],int numProd) {

    printf("Type the new weight of the product\n");
    printf("Weight:");
    fflush(stdin);
    scanf("%f",&products[numProd].weight);
    printf("\n");

}

//Fun��o que edita a quantidade de um produto.

void editProductQuantity(PRODUCT products[],int numProd) {

    printf("Type the new quantity of the product\n");
    printf("Quantity:");
    fflush(stdin);
    scanf("%d",&products[numProd].quantity);
    printf("\n");
}

//Fun��o que edita o pre�o de um produto.

void editProductPrice(PRODUCT products[],int numProd) {

    printf("Type the new price of the product\n");
    printf("Price:");
    fflush(stdin);
    scanf("%f",&products[numProd].price);
    printf("\n");

}

//Fun��o de inteiro que retorna 1 se o id do produto ja estiver cadastrado.

int checkProdIdIsCad(PRODUCT products[],int tempId) {

    int counter;

    for(counter=0; counter<PRDTQ; counter++) {

        //Compara o inteiro recebido com os ids dos produtos do mercado.

        if(tempId == products[counter].id) {

            return 1;
            break;

        }

    }

    return 0;

}

int checkAdminIdIsCad(ADMIN admins[],int tempId) {

    int counter;

    for(counter=0; counter<PRDTQ; counter++) {

        //Compara o inteiro recebido com os ids dos admins do mercado.

        if(tempId == admins[counter].id) {

            return 1;
            break;

        }

    }

    return 0;

}

//Funcao que retorna 1 se ja ha um produto cadastrado com o nome passado como parametro.

int checkProdNameCad(PRODUCT products[],char tempString[]){

    int counter;

    for(counter = 0;counter <PRDTQ;counter ++){

        if(strncmp(products[counter].name,tempString,25) == 0){

            return 1;
            break;

        }

    }

    return 0;

}

//Funcao que retorna 1 se ja ha um admin cadastrado com o Login passado como parametro.

int checkAdminLoginCad(ADMIN admins[],char tempString[]){

    int counter;

    for(counter = 0;counter <ADMQ;counter ++){

        if(strncmp(admins[counter].login,tempString,15) == 0){

            return 1;
            break;

        }

    }

    return 0;

}

//Funcao que cadastra o nome de um administrador e retorna o nome cadastrado.

char* cadAdminName(ADMIN admins[]){

    char tempName[25];

        printf("Type the name of the new administrator\n");
        printf("Name:");
        fflush(stdin);
        fgets(tempName,25,stdin);
        removeBrokenLine(tempName);
        printf("\n");   
    
    return tempName;

}

//Funcao que cadastra o login de um administrador e retorna o nome cadastrado.

char* cadAdminLogin(ADMIN admins[]){

    char tempName[25];
    
    do{

        printf("Type the login of the new administrator\n");
        printf("Name:");
        fflush(stdin);
        fgets(tempName,25,stdin);
        removeBrokenLine(tempName);
        printf("\n");    
    
    
    if(checkAdminLoginCad(admins,tempName) == 1){

        printf("Name already registred.Try again with a distint name!!!\n\n");
        
    }

    }while(checkAdminLoginCad(admins,tempName) == 1);
    
    return tempName;

}

char* cadAdminPassword(ADMIN admins[]){

    char tempName[25];

        printf("Type the password of the new administrator\n");
        printf("Name:");
        fflush(stdin);
        fgets(tempName,25,stdin);
        removeBrokenLine(tempName);
        printf("\n");   
    
    return tempName;

}

//Funcao que cadastra o nome de um produto e retorna o nome cadastrado.

char* cadProductName(PRODUCT products[]){

    char tempName[25];
    
    do{

        printf("Type the name of the new product\n");
        printf("Name:");
        fflush(stdin);
        fgets(tempName,25,stdin);
        removeBrokenLine(tempName);
        printf("\n");    
    
    
    if(checkProdNameCad(products,tempName) == 1){

        printf("Name already registred.Try again with a distint name!!!\n\n");
        
    }

    }while(checkProdNameCad(products,tempName) == 1);
    

    return tempName;

}

//Funcao que cadastra o id de um produto e retorna o id cadastrado.

int cadProductID(PRODUCT products[]){

    int tempId;

    do{

    printf("Type the id of the new product\n");
    printf("ID:");
    fflush(stdin);
    scanf("%d",&tempId);
    printf("\n");

    if(checkProdIdIsCad(products,tempId) == 1){

        printf("ID already registred.Try again with a distint id !!!\n\n");
    }

    }while(checkProdIdIsCad(products,tempId) == 1);

    return tempId;

}

//Funcao que cadastra o id de um administrador e retorna o id cadastrado.

int cadAdminID(ADMIN admins[]){

    int tempId;

    do{

    printf("Type the id of the new product\n");
    printf("ID:");
    fflush(stdin);
    scanf("%d",&tempId);
    printf("\n");

    if(checkProdIdIsCad(admins,tempId) == 1){

        printf("ID already registred.Try again with a distint id !!!\n\n");
   
    }

    }while(checkProdIdIsCad(admins,tempId) == 1);

    return tempId;

}

//Fun��o que cadastra o peso de um produto e retorna o peso cadastrado.

float cadProductWeight(){

   float tempWeight;

    printf("Type the weight of the new product\n");
    printf("Weight:");
    fflush(stdin);
    scanf("%f",&tempWeight);
    printf("\n");

    return tempWeight;
}

//Fun��o que cadastra a quantidade de um produto e retorna a quantiade cadastrada.

int cadProductQuantity(){

    int tempQuantity;

    printf("Type the quantity of the new product\n");
    printf("Quantity:");
    fflush(stdin);
    scanf("%d",&tempQuantity);
    printf("\n");

    return tempQuantity;

}

//Fun��o que cadastra a quantidade de um produto e retorna a quantiade cadastrada.

float cadProductPrice(){

    float tempPrice;

    printf("Type the price of the new product\n");
    printf("Price:");
    fflush(stdin);
    scanf("%f",&tempPrice);
    printf("\n");

    return tempPrice;

}

//Funcao que cadastra um produto no mercado.

PRODUCT cadProd(PRODUCT products[],int* cpP) {

    PRODUCT productTemp;

    strncpy(productTemp.name,cadProductName(products),25);

    productTemp.id = cadProductID(products);

    productTemp.price = cadProductPrice();

    productTemp.quantity = cadProductQuantity();

    productTemp.weight = cadProductWeight();

    (*cpP)++;

    return productTemp;

}

//Funcao que cadastra um produto no mercado.

ADMIN cadAdmin(ADMIN admins[],int* cpA) {

    ADMIN adminTemp;

    strncpy(adminTemp.name,cadAdminName(admins),25);
    removeBrokenLine(adminTemp.name);

    strncpy(adminTemp.login,cadAdminLogin(admins),15);
    removeBrokenLine(adminTemp.login);
    
    strncpy(adminTemp.password,cadAdminPassword(admins),15);
    removeBrokenLine(adminTemp.password);

    adminTemp.id = cadAdminID(admins);

    (*cpA)++;

    return adminTemp;

}

//Funcao que verifica se ha slots de produtos disponíveis no mercado.

int checkProdSlotsDisponibility(PRODUCT products[]){

    int counter;

    for(counter = 0;counter <PRDTQ;counter++){

        if(products[counter].id == -1){

            return 1;

        }
    }

    return 0;

}

//Funcao que verifica se ha slots de admins disponíveis no mercado.

int checkAdminSlotsDisponibility(ADMIN admins[]){

    int counter;

    for(counter = 0;counter <PRDTQ;counter++){

        if(admins[counter].id == -1){

            return 1;

        }
    
    }

    return 0;
    
}

//Funcao que atraves do numero do produto imprime os atributos desse produto.

void showProduct(PRODUCT products[],int prodNum) {

    system("cls");

    printf("\nProduct founded!!\n\n");

    printf("Name:%s\n",products[prodNum].name);
    printf("ID:%i\n",products[prodNum].id);
    printf("Weight:%f\n",products[prodNum].weight);
    printf("Quantity:%i\n",products[prodNum].quantity);
    printf("Price:%f\n\n",products[prodNum].price);

}

void showAdmin(ADMIN admins[],int adminNum) {

    system("cls");

    printf("\nProduct founded!!\n\n");

    printf("Name:%s\n",admins[adminNum].name);
    printf("Login:%s\n",admins[adminNum].login);
    printf("Password:%s\n",admins[adminNum].password);
    printf("ID:%d\n\n",admins[adminNum].id);

}

//Fun��o que atrav�s do n�mero do produto apaga os atributos desse produto no slot.

void clearProdSlot(PRODUCT products[],int slotNum) {

    strncpy(products[slotNum].name,"                        ",25);
    removeBrokenLine(products[slotNum].name);
    products[slotNum].price = 0.0;
    products[slotNum].quantity = 0;
    products[slotNum].weight = 0.0;
    products[slotNum].id = -1;

}

/*Fun��o que recebe um numero do usuario e atraves desse numero
 decide se o programa voltara para o menu ou buscara outro produto*/

int searchOtherProduct() {

    int option;

    do {

        menuSearchOtherProductInterface();

        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

}

int searchOtherAdmin() {

    int option;

    do {

        menuSearchOtherAdminInterface();

        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

}

/*Fun��o que recebe um n�mero do usu�rio e atr�ves desse n�mero
 decide se o programa voltar� para o menu ou editar� outro produto*/

int editOtherProduct() {

    int option;

    do {

        menuEditOtherProductInterface();
        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

    system("cls");

}

/*Funcao que recebe um numero do usuario e atraves desse numero
 decide se o programa voltara para o menu ou editara outro produto*/

int editOtherAdmin() {

    int option;

    do {

        menuEditOtherAdminInterface();
        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

    system("cls");

}

/*Funcao que recebe um numero do usuario e atraves desse numero
 decide se o programa voltara para o menu ou adicionara outro produto*/

int addOtherProduct(){

int option;


    do {


        menuAddOtherAdminInterface();
        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

    system("cls");

}

int addOtherAdmin(){

int option;


    do {


        menuAddOtherAdminInterface();
        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

    system("cls");



}

int removeOtherProduct() {

    int option;

    do {


        menuRemoveOtherProductInterface();
        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

    system("cls");

}

int restockOtherProduct() {

    int option;

    do {


        menuRestockOtherProductInterface();
        option = setNum();

        switch(option) {

        case 1: {

            return 1;

            break;
        }

        case 2 : {

            return 0;

            break;

        }

        default : {

            printf("Wrong option!!.Try again with a distint option\n\n");
            break;

        }

        }

    } while(option != 1 && option != 2);

    system("cls");

}

//Funcao que adciona uma nova quantidade de produtos na váriavel de quantidade de um produto.

void addProdQuanty(PRODUCT products[],int prodNum){

    int addQuantNum;

    printf("Type the amount that will be add\n");
    printf("Amount:");
    addQuantNum = setNum();

    products[prodNum].quantity += addQuantNum; 

}

///Funcao que busca um produto cadastrado no mercado.

void searchProduct(PRODUCT products[]) {

    system("cls");

    int tempId;
    int prodNum;
    int otherProd;

    do {

        printf("Type the id of the product that you want to search\n");
        printf("ID:");

        tempId = setNum();

        if(checkProdIdIsCad(products,tempId) == 1) {

            prodNum = getProdNum(products,tempId);
            showProduct(products,prodNum);
            otherProd = searchOtherProduct();

        }

        else {

            printf("ID not registred.Try again with a distint a ID!!\n\n");

        }

    } while(checkProdIdIsCad(products,tempId) != 1 || otherProd == 1);

}

void restockProduct(PRODUCT products[]){

    system("cls");

    int tempId;
    int otherProd;
    int prodNum;

   do{

        printf("Type the id of the product that you want restock\n");
        printf("ID:");

        tempId = setNum();
    
        if(checkProdIdIsCad(products,tempId) == 1){

            prodNum = getProdNum(products,tempId);
            showProduct(products,prodNum);
            addProdQuanty(products,prodNum);
            otherProd = restockOtherProduct();

        }   
    
    }while(checkProdIdIsCad(products,tempId) == 0 || otherProd  == 1 );

}

void searchAdmin(ADMIN admins[]) {

    system("cls");

    char tempId;
    int adminNum;
    int otherAdmin;

    do {

        printf("Type the id of the admin you want to search\n");
        printf("ID:");

        tempId = setNum();

        if(checkAdminIdIsCad(admins,tempId) == 1) {

            adminNum = getAdminNum(admins,tempId);
            showAdmin(admins,adminNum);
            otherAdmin = searchOtherAdmin();

        }

        else {

            printf("ID not registred.Try again with a distint a ID!!\n\n");

        }

    } while(checkAdminIdIsCad(admins,tempId) != 1 || otherAdmin == 1);

}



///Fun��o que cadastra um produto no mercado.

void addProduct(PRODUCT products[],int* cpP) {

    system("cls");

    PRODUCT productTemp;

    int key;
    int otherProd;
    int counter;

    if(checkProdSlotsDisponibility(products) == 1){


    while(*cpP < PRDTQ) {

        for(;*cpP < PRDTQ; (*cpP)++) {

            if(products[*cpP].id == -1) {

                do {

                    subMenuAddProductInterface(cpP);
                    key = setNum();

                    switch(key) {

                    case 1: {

                        products[*cpP] = cadProd(products,cpP);
                        otherProd = addOtherProduct();
                        break;

                    }

                    case 2: {


                        break;
                    }

                    case 3: {

                        break;

                    }

                    default: {

                        printf("Invalid option.Try again with a distint option\n\n");

                    }

                    }

                } while(key != 1 && key != 2 && key != 3);

            }

            if(key == 3 || otherProd == 0) {

                break;
            }

        }

        break;
    }

    }

    else{

        printf("The store's stocks are all full.Try a different option!!\n\n");

    }

}

///Funcao que cadastra um administrador no mercado.

void addAdmin(ADMIN admins[],int* cpA) {

    system("cls");

    ADMIN adminTemp;

    int key;
    int otherAdmin;
    int counter;

    if(checkAdminSlotsDisponibility(admins) == 1){


    while(*cpA < ADMQ) {

        for(; *cpA < ADMQ; (*cpA)++) {

            if(admins[*cpA].id == -1) {

                do {

                    subMenuAddAdminInterface(cpA);
                    key = setNum();

                    switch(key) {

                    case 1: {

                        admins[*cpA] = cadAdmin(admins,cpA);
                        otherAdmin   = addOtherAdmin();
                        break;

                    }

                    case 2: {


                        break;
                    }

                    case 3: {

                        break;

                    }

                    default: {

                        printf("Invalid option.Try again with a distint option\n\n");

                    }

                    }

                } while(key != 1 && key != 2 && key != 3);

            }

            if(key == 3 || otherAdmin == 0) {

                break;
            }

        }

        break;
    }

    }

    else{

        printf("The admin's stocks are all full.Try a different option!!\n\n");

    }

}



///Fun��o que inicializa os produtos do mercado.

void removeProduct(PRODUCT products[],int* cpP) {

    system("cls");

    int key;
    int prodId;
    int prodNum;
    int otherProd;

    do {
        
        printf("Type the id of the product you want to remove!\n");
        printf("ID:");
        prodId = setNum();
        printf("\n");

        if(checkProdIdIsCad(products,prodId) == 1) {

            prodNum = getProdNum(products,prodId);
            showProduct(products,prodNum);


            do {

                subMenuRemoveProductInterface();
                key = setNum();
                printf("\n");


                switch(key) {

                case 1 : {

                    clearProdSlot(products,prodNum);

                    if(compnumWithcounterPointer(prodNum,cpP) == 1) {

                        *cpP = prodNum;
                    }

                    otherProd = removeOtherProduct();

                    break;

                }

                case 2 : {

                    break;

                }



                default : {

                    printf("Invalid option.Try again\n\n");
                    break;

                }

                }


            } while(key != 1 && key != 2);

        }

        else {

            printf("ID not registred.Try again with a distint id!!\n\n");

        }

        if(key == 2 || otherProd == 0) {

            break;
        }

    } while(checkProdIdIsCad(products,prodNum) != 1 || otherProd == 1);


}

//Funcao que edita os atributos de um produto.
void editProduct(PRODUCT products[]) {

    int key;
    int prodId;
    int prodNum;
    int otherProd;

    do {

        printf("Type the id of the product you want to edit!\n");
        printf("ID:");
        prodId = setNum();

        if(checkProdIdIsCad(products,prodId) == 1) {

            prodNum = getProdNum(products,prodId);
            showProduct(products,prodNum);

            do {

                subMenuEditProductInterface();

                key = setNum();

                switch(key) {

                case 1 : {

                    editProductName(products,prodNum);
                    otherProd = editOtherProduct();
                    break;
                }

                case 2 : {

                    editProductID(products,prodNum);
                    otherProd = editOtherProduct();
                    break;
                }

                case 3 : {

                    editProductWeight(products,prodNum);
                    otherProd = editOtherProduct();
                    break;

                }

                case 4 : {

                    editProductQuantity(products,prodNum);
                    otherProd = editOtherProduct();
                    break;

                }

                case 5 : {

                    editProductPrice(products,prodNum);
                    otherProd = editOtherProduct();
                    break;

                }

                case 6: {

                    break;


                }

                default: {

                    printf("\nInvalid option,try again!!\n\n");

                    break;
                }

                }

            } while(key != 1 && key != 2 && key != 3 && key != 4 && key != 5 && key != 6);

        }

        else {

            printf("ID not registred.Try again with a distint id!!\n\n");

        }

        if(key == 6 || otherProd == 0) {

            break;
        }

    } while(checkProdIdIsCad(products,prodNum) != 1 || otherProd == 1);

}


//Funcao que edita os atributos de um produto.
void editAdmin(ADMIN admins[]) {

    int key;
    int adminId;
    int adminNum;
    int otherAdmin;

    do {

        printf("Type the id of the admin you want to edit!\n");
        printf("ID:");
        adminId = setNum();

        if(checkAdminIdIsCad(admins,adminId) == 1) {

            adminNum = getAdminNum(admins,adminId);
            showAdmin(admins,adminNum);

            do {

                subMenuEditAdminInterface();

                key = setNum();

                switch(key) {

                case 1 : {

                    editAdminName(admins,adminNum);
                    otherAdmin = editOtherAdmin();
                    break;

                }

                case 2 : {

                    editAdminLogin(admins,adminNum);
                    otherAdmin = editOtherAdmin();
                    break;

                }

                case 3 : {

                    editAdminPassword(admins,adminNum);
                    otherAdmin = editOtherAdmin();
                    break;

                }

                case 4 : {

                    editAdminID(admins,adminNum);
                    otherAdmin = editOtherAdmin();
                    break;

                }

                case 5: {

                    break;

                }

                default: {

                    printf("\nInvalid option,try again!!\n\n");

                    break;
                }

                }

            } while(key != 1 && key != 2 && key != 3 && key != 4 && key != 5);

        }

        else {

            printf("ID not registred.Try again with a distint id!!\n\n");

        }

        if(key == 6 || otherAdmin == 0) {

            break;
        }

    } while(checkAdminIdIsCad(admins,adminNum) != 1 || otherAdmin == 1);

}

///Funcao que apresenta a interface do menu.
void menu(PRODUCT products[],ADMIN admins[],int* cpP,int* cpA) {

    ///Declaracao da variavel que controla o menu.
    int key;

    do {


        showMenuInterface();

        key = setNum();

        switch(key) {

        case 1 : {

            searchProduct(products);

            break;
        }

        case 2 : {

            searchAdmin(admins);
    
            break;

        }

        case 3 : {

            editProduct(products);
            
            break;

        }

        case 4 : {
            
            editAdmin(admins);
            break;

        }

        case 5 : {
            
            removeProduct(products,cpP);
            break;

        }

        case 6 : {

            addProduct(products,cpP);
            break;
            
        }

        case 7 : {

            addAdmin(admins,cpA);
            break;

        }

        case 8 :{
            
            showRegistredProducts(products);
            break;

        }

        case 9 : {

            showRegistredAdmins(admins);
            break;
        }

        case 10 : {

            restockProduct(products);
            break;
            
        }

        case 11: {

            showEndOfShopMessage();
            break;

        }

        default : {

            printf("\nInvalid option,try again!!\n\n");
            break;

        }

        }

    } while(key != 11);
}

PRODUCT fillEmptyProdSlot(){

    PRODUCT tempProduct;

    strncpy(tempProduct.name,"                        ",25);
    removeBrokenLine(tempProduct.name);
    tempProduct.id = -1;
    tempProduct.price = 0.0;
    tempProduct.quantity = 0;
    tempProduct.weight = 0.0;

    return tempProduct;

}

ADMIN fillEmptyAdmSlot(){

    ADMIN tempAdmin;

    strncpy(tempAdmin.name,"                        ",25);
    removeBrokenLine(tempAdmin.name);
    strncpy(tempAdmin.login,"              ",15);
    removeBrokenLine(tempAdmin.login);
    strncpy(tempAdmin.password,"              ",15);
    removeBrokenLine(tempAdmin.password);
    tempAdmin.id = -1;

    return tempAdmin;

}

/*
void fillEmptySlots(PRODUCT products[]){

    int counter;

    for(counter = 0;counter<PRDTQ;counter++){

        products[counter] = fillEmptySlot();

    }


}*/

void initialize() {

///Declara��o do vetor estruturado que cont�m os produtos do mercado.

    //Array de estrutura do tipo produto.

    PRODUCT products[PRDTQ];
    ADMIN   admins[ADMQ];

    int counterP = 3;
    int* cpP = &counterP;
    
    int counter;

    int counterA = 2;
    int* cpA = &counterA;

    //Declaração de alguns produtos do mercado

    products[0] = (PRODUCT) {
        "chocolate",1,2.5,50,10.0
    };
    products[1] = (PRODUCT) {
        "coca-cola",2,2.7,50,10.0
    };
    products[2] = (PRODUCT) {
        "candy",3,2.0,100,1.5
    };

    //Declaração de alguns administradores do mercado

    admins[0] = (ADMIN){

        "Gabriel","gs9878","1234",1

    };

    admins[1] = (ADMIN){

        "Jose","zefo32","4321",2

    };

   //Inicializa os slots dos produtos vazios.

    for(counter = 3; counter < PRDTQ ; counter++) {

        products[counter] = fillEmptyProdSlot();

    }

    //Inicializa os slots dos administradores vazios.

    for(counter = 2; counter < ADMQ ; counter++) {

        admins[counter] = fillEmptyAdmSlot();

    }

    //Inicializa os slots dos administradores vazios.

    for(counter = 3; counter < 50 ; counter++) {

        products[counter] = fillEmptyProdSlot();

    }

///Chamada da fun��o que inicializa o menu.

    menu(products,admins,cpP,cpA);

}

int main() {

///Declara��o da fun��o que inicializa o programa.
    initialize();

}
