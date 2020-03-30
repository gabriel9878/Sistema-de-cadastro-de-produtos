#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Constantes

#define PRDTQ 50

//ESTRUTURAS

//Estrutura de um produto.
typedef struct {

    char name[25];
    int id;
    float weight;
    int quantity;
    float price;

} PRODUCT;

//Função que imprime a interface do menu na tela.

void showMenuInterface() {



    printf("|---------------------------------------------------------------------|\n");
    printf("|                                                                     |\n");
    printf("|-----------------------|[PRODUCTS REGISTER]|-------------------------|\n");
    printf("|                                                                     |\n");
    printf("|---------------------------------------------------------------------|\n\n\n");

    printf("|[1]|:Search product\n");
    printf("|[2]|:Edit product\n");
    printf("|[3]|:Remove product\n");
    printf("|[4]|:Add product\n");
    printf("|[5]|:Show registred products\n");
    printf("|[9]|:Close program\n\n");
    printf("Key:");

}

//Função de inteiro que retorna 1 se o numero do produto em questão for menor que o contador dos produtos.
int compProdnum_CounterProd(int prodNum,int* counterProd) {


    if(prodNum < *counterProd) {

        return 1;

    }

    return 0;

}

//Função que remove quebra de linha de uma string.

void removeBrokenLine(char *string) {
    if(string != NULL && strlen(string) > 0) {
        short tamanho = strlen(string);

        if(string[tamanho-1] == '\n') {
            string[tamanho-1] = '\0';
        }
    }
}

//Função que recebe um número como opção do usuário

int getOption() {

    int option;

    fflush(stdin);
    scanf("%d",&option);
    printf("\n");

    return option;

}

//função que atráves do id descobre o número do produto no array dos produtos.

int getProdNum(PRODUCT products[],int prodId) {

    int counter;

    for(counter = 0; counter < PRDTQ; counter++) {

        if(prodId == products[counter].id) {

            break;
        }

    }

    return counter;
}

//Função que imprime os produtos cadastrados do mercado na tela.

void showProducts(PRODUCT products[]) {

    int counter;

    for(counter=0; counter<PRDTQ; counter++) {

        if(products[counter].id != -1) {

            printf("Product %d\n\n",counter+1);
            printf("Name:%s\n",products[counter].name);
            printf("ID:%i\n\n",products[counter].id);

        }

    }

}

//Imprime na tela a mensagem de fim do programa.

void showEndOfShopMessage(){

    printf("\n\n__________________________|[VOLTE SEMPRE]|____________________________\n");

}

//Imprime na tela a mensagem que pergunta se o usuário deseja buscar outro produto.

void menuSearchOtherProductInterface() {

    printf("You want to search other product ?\n\n");
    printf("1-Search other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usuário deseja editar outro produto.

void menuEditOtherProductInterface() {

    printf("You want to edit other product ?\n\n");
    printf("1-Edit other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usuário deseja remover outro produto.

void menuRemoveOtherProductInterface() {

    printf("You want to remove other product ?\n\n");
    printf("1-Remove other product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Imprime na tela a mensagem que pergunta se o usuário deseja adicionar outro produto.

void menuAddOtherProductInterface() {

    printf("You want to add other product ?\n\n");
    printf("1-Add other product\n");
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

//Imprime na tela uma interface que pergunta se o usuário quer adicionar um produto no slot encontrado.

void subMenuAddProductInterface(int *prodNum) {

    printf("Slot %d is free.You wanna to add a product in this slot?\n\n",(*prodNum) + 1);
    printf("1-Add a new product in this slot\n");
    printf("2-Go to the next slot\n");
    printf("3-Go back to menu\n");
    printf("Key:");

}

//Imprime na tela uma interface que pergunta se o usuário quer adicionar um produto no slot encontrado.

void subMenuRemoveProductInterface() {

    printf("Are you sure you want to remove this product ?\n\n");
    printf("1-Remove product\n");
    printf("2-Go back to menu\n\n");
    printf("Key:");

}

//Função que edita o nome de um produto.

void editProductName(PRODUCT products[],int numprod) {

    printf("Type the new name of the product\n");
    printf("Name:");
    fflush(stdin);
    fgets(products[numprod].name,25,stdin);
    removeBrokenLine(products[numprod].name);
    printf("\n");

}

//Função que edita o id de um produto.

void editProductID(PRODUCT products[],int numProd) {

    printf("Type the new ID of the product\n");
    printf("ID:");
    fflush(stdin);
    scanf("%d",&products[numProd].id);
    printf("\n");

}

//Função que edita o peso de um produto.

void editProductWeight(PRODUCT products[],int numProd) {

    printf("Type the new weight of the product\n");
    printf("Weight:");
    fflush(stdin);
    scanf("%f",&products[numProd].weight);
    printf("\n");


}

//Função que edita a quantidade de um produto.

void editProductQuantity(PRODUCT products[],int numProd) {

    printf("Type the new quantity of the product\n");
    printf("Quantity:");
    fflush(stdin);
    scanf("%d",&products[numProd].quantity);
    printf("\n");
}

//Função que edita o preço de um produto.

void editProductPrice(PRODUCT products[],int numProd) {

    printf("Type the new price of the product\n");
    printf("Price:");
    fflush(stdin);
    scanf("%f",&products[numProd].price);
    printf("\n");

}

//Função que cadastra o id de um produto e retorna o id cadastrado.

int cadProductID(PRODUCT products[]){

    int tempId;

    do{

    printf("Type the id of the new product\n");
    printf("ID:");
    fflush(stdin);
    scanf("%d",&tempId);
    printf("\n");

    if(checkProdsIdCad(products,tempId) == 1){

        printf("ID already registred.Try again with a distint id !!!\n\n");
    }

    }while(checkProdsIdCad(products,tempId) == 1);

    return tempId;

}

//Função que cadastra o peso de um produto e retorna o peso cadastrado.

float cadProductWeight(){

   float tempWeight;

    printf("Type the weight of the new product\n");
    printf("Weight:");
    fflush(stdin);
    scanf("%f",&tempWeight);
    printf("\n");

    return tempWeight;
}

//Função que cadastra a quantidade de um produto e retorna a quantiade cadastrada.

int cadProductQuantity(){

    int tempQuantity;

    printf("Type the quantity of the new product\n");
    printf("Quantity:");
    fflush(stdin);
    scanf("%d",&tempQuantity);
    printf("\n");

    return tempQuantity;
}

//Função que cadastra a quantidade de um produto e retorna a quantiade cadastrada.

float cadProductPrice(){

    float tempPrice;

    printf("Type the price of the new product\n");
    printf("Price:");
    fflush(stdin);
    scanf("%f",&tempPrice);
    printf("\n");

    return tempPrice;

}

//Função de inteiro que retorna 1 se o id do produto ja estiver cadastrado.

int checkProdsIdCad(PRODUCT products[],int tempId) {

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

//Função que cadastra um produto no mercado
PRODUCT cadProd(PRODUCT products[],PRODUCT productTemp,int* prodNum) {

    do{

    printf("Type the name of the new product\n");
    printf("Name:");
    fflush(stdin);
    fgets(productTemp.name,25,stdin);
    removeBrokenLine(productTemp.name);
    printf("\n");

    if(checkProdNameCad(products,productTemp.name) == 1){

        printf("Name already registred.Try again with a distint name!!!\n\n");
    }

    }while(checkProdNameCad(products,productTemp.name) == 1);

    productTemp.id = cadProductID(products);

    productTemp.price = cadProductPrice();

    productTemp.quantity = cadProductQuantity();

    productTemp.weight = cadProductWeight();

    (*prodNum)++;

    return productTemp;

}

//Função que atráves do número do produto imprime os atributos desse produto.

void showProduct(PRODUCT products[],int prodNum) {

    system("cls");

    printf("\nProduct founded!!\n\n");

    printf("Name:%s\n",products[prodNum].name);
    printf("ID:%i\n",products[prodNum].id);
    printf("Weight:%f\n",products[prodNum].weight);
    printf("Quantity:%i\n",products[prodNum].quantity);
    printf("Price:%f\n\n",products[prodNum].price);

}

//Função que através do número do produto apaga os atributos desse produto.

void clearProdSlot(PRODUCT products[],int slotNum) {

    strncpy(products[slotNum].name,"                         ",25);
    removeBrokenLine(products[slotNum].name);
    products[slotNum].price = 0.0;
    products[slotNum].quantity = 0;
    products[slotNum].weight = 0.0;
    products[slotNum].id = -1;

}

/*Função que recebe um número do usuário e atráves desse número
 decide se o programa voltará para o menu ou buscará outro produto*/

int searchOtherProduct() {

    int option;


    do {

        menuSearchOtherProductInterface();

        option = getOption();

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

/*Função que recebe um número do usuário e atráves desse número
 decide se o programa voltará para o menu ou editará outro produto*/

int editOtherProduct() {


    int option;


    do {


        menuEditOtherProductInterface();
        option = getOption();

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

/*Função que recebe um número do usuário e atráves desse número
 decide se o programa voltará para o menu ou adicionará outro produto*/

int addOtherProduct(){

int option;


    do {


        menuAddOtherProductInterface();
        option = getOption();

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
        option = getOption();

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



///Função que busca um produto cadastrado no mercado.

int searchProduct(PRODUCT products[]) {

    system("cls");

    int tempId;
    int prodNum;
    int otherProd;

    do {

        printf("Type the id of the product you want to search\n");
        printf("ID:");

        tempId = getOption();

        if(checkProdsIdCad(products,tempId) == 1) {

            prodNum = getProdNum(products,tempId);
            showProduct(products,prodNum);
            otherProd = searchOtherProduct();

        }

        else {

            printf("ID not registred.Try again with a distint a ID!!\n\n");

        }

    } while(checkProdsIdCad(products,tempId) != 1 || otherProd == 1);

}

///Função que cadastra um produto no mercado.

void addProduct(PRODUCT products[],int* counterProd) {

    system("cls");

    PRODUCT productTemp;

    int key;
    int otherProd;
    int counter;
    int disponibility = 1;

    for(counter = 0;counter<50;counter++){

       if(products[counter].id == -1){


            disponibility = 0;
            printf("\n\n");
            break;
       }

    }

    if(disponibility == 0){


    while(*counterProd < PRDTQ) {

        for(; *counterProd < PRDTQ; (*counterProd)++) {

            if(products[*counterProd].id == -1) {

                do {

                    subMenuAddProductInterface(counterProd);
                    key = getOption();

                    switch(key) {

                    case 1: {

                        products[*counterProd] = cadProd(products,productTemp,counterProd);
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

///Função que inicializa os produtos do mercado.

void removeProduct(PRODUCT products[],int* counterProd) {

    system("cls");

    int key;
    int prodId;
    int prodNum;
    int otherProd;

    do {

        printf("Type the id of the product you want to remove!\n");
        printf("ID:");
        prodId = getOption();
        printf("\n");

        if(checkProdsIdCad(products,prodId) == 1) {

            prodNum = getProdNum(products,prodId);
            showProduct(products,prodNum);


            do {

                subMenuRemoveProductInterface();
                key = getOption();
                printf("\n");


                switch(key) {

                case 1 : {

                    clearProdSlot(products,prodNum);

                    if(compProdnum_CounterProd(prodNum,counterProd) == 1) {

                        *counterProd = prodNum;
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



    } while(checkProdsIdCad(products,prodNum) != 1 || otherProd == 1);


}

///Função que edita os atributos de um produto.
void editProduct(PRODUCT products[]) {

    int key;
    int prodId;
    int prodNum;
    int otherProd;

    do {

        printf("Type the id of the product you want to edit!\n");
        printf("ID:");
        prodId = getOption();

        if(checkProdsIdCad(products,prodId) == 1) {

            prodNum = getProdNum(products,prodId);
            showProduct(products,prodNum);

            do {

                subMenuEditProductInterface();

                key = getOption();

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

    } while(checkProdsIdCad(products,prodNum) != 1 || otherProd == 1);

}

///função que apresenta a interface do menu.
void menu(PRODUCT products[],int* counterProd) {

    ///Declaração da váriavel que controla o menu.
    int key;

    do {


        showMenuInterface();

        scanf("%d",&key);
        fflush(stdin);
        printf("\n");

        switch(key) {

        case 1 : {

            searchProduct(products);

            break;
        }

        case 2 : {

            editProduct(products);
            break;

        }

        case 3 : {

            removeProduct(products,counterProd);
            break;

        }

        case 4 : {

            addProduct(products,counterProd);
            break;

        }

        case 5 : {

            showProducts(products);
            break;

        }

        case 9 : {

            showEndOfShopMessage();
            break;
        }

        default : {

            printf("\nInvalid option,try again!!\n\n");
            break;

        }

        }

    } while(key != 9);
}

void initialize() {

///Declaração do vetor estruturado que contém os produtos do mercado.

    PRODUCT products[PRDTQ];

    int counterP = 3;
    int *counterpP = &counterP;
    int counter;

    products[0] = (PRODUCT) {
        "chocolate",1,2.5,50,10.0
    };
    products[1] = (PRODUCT) {
        "coca-cola",2,2.7,50,10.0
    };
    products[2] = (PRODUCT) {
        "candy",3,2.0,100,1.5
    };


    for(counter = 3; counter < 50 ; counter++) {

        products[counter] = (PRODUCT) {
            "                       ",-1,0.0,0,0.0
        };

    }

///Chamada da função que inicializa o menu.

    menu(products,counterpP);

}

int main() {

///Declaração da função que inicializa o programa.
    initialize();

}
