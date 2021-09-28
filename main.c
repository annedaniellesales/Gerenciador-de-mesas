//Gerenciador de mesas em um restaurante
#include <string.h>
#include <stdlib.h.>
#include <stdio.h>
#include <locale.h> 
#include <ctype.h>

int main(){
setlocale(LC_ALL, "portuguese");/*Maneira de utilizar acento no programa*/
system("chcp 1252 > nul");

int op,mesa,i=0;

typedef struct{
	char nome[100];
	float contato;	
}cadastro;
cadastro func[20];


for(i=0; i<20; i++) {
strcpy(func[i].nome, "NULL");
func[i].contato = 0.0;
}

while(1){
printf("\nRESERVA DE MESAS NO ANNE'S\nDigite o número que corresponde a sua opção\n1-Ver disponibilidade de mesas\n2-Reserva de mesa\n3-Cancelar uma reserva\n4-Finalizar o programa.\n");
printf("\n");
printf("Digite a opção desejada:");
scanf("%d",&op);


//OPÇÃO 1 - CONSULTAR DISPONIBILIDADE DAS MESAS
if(op==1){ //Relação de disponibilidade
printf("As mesas disponíveis são:");
for(i=1;i<=20;i++){
if(func[i].contato==0){
	printf("%d ",i);
}
}printf("\n");
printf("As reservas são:\n");
for(i=1;i<=20;i++){
if(i>=1 && i<=20){
	if(func[i].contato == 0){

}else{ //Relação das reservas existentes
	printf("Mesa %d reservada por %s com contato %.f\n",i,func[i].nome,func[i].contato);
}
}

}

}else if(op!=1 && op!=2){ //Outras opções do menu
	if(op!=3 && op!=4){
		printf("Opção inexistente.Tente novamente!\n");
	}
}

//OPÇÃO 2 - RESERVA DE MESAS
if(op==2){
for(i=0;i<20;i++){
printf("Digite a mesa que quer reservar: ");
scanf("%d",&mesa);
if(mesa >=1 && mesa <=20){
if(func[mesa].contato==0){
}else{
	printf("Infelizmente,mesa reservada!Tente novamente!\n"); //Mesa reservada
	break;
}
}else{
	printf("Mesa inexistente!Tente novamente!\n"); //Mesa inexistente
	break;
}

printf("Digite o nome do reservador:");
setbuf(stdin,NULL);
gets(func[mesa].nome);
printf("Digite o contato do reservador:");
scanf("%f",&func[mesa].contato);
printf("Mesa %d reservada!",mesa);
break;

}
}
//OPÇÃO 3 - CANCELAR UMA RESERVA
if(op==3){
	printf("Digite o número da mesa que cancelar:");
	scanf("%d",&mesa);
	func[mesa].nome==0;
	func[mesa].contato=0;
	printf("Reserva da mesa %d Cancelada!\n",mesa);
}
//OPÇÃO 4 - FINALIZAR O PROGRAMA
if(op==4){
	printf("Programa finalizado!Obrigada!");
	break;
}

}
}