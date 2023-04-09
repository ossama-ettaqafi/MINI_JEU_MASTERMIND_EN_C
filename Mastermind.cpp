#include <stdio.h>
#include <conio.h>
#include <windows.h>

//######################### LES FOCTIONS : (Prototyping) #########################
//Les menus de jeu
void principal_menu();
void niveau_menu();

//En relation avec les menus
void guide();
void jeu();
void retourner(int);

//Les titres qui s'affichent en haut
void titres(int,int);

//En relation avec la fonction jeu
void new_scan(int);
int verifier(char,int,int);
void comp_affich();
void jok(int);
void resultat(int);

//Fontion de colors
void new_printf(char text[]);
//######################### LES VARIABLES GLOBALES : #########################
char Joueur[2][5]; //Joueur: un tableau qui va contenire les caractères (nombres) entrés par les deux jouers

int var[3];
//var[0]: bien placé
//var[1]: mal placé
//var[2]: n'existe pas

int essai,utiliser_joker,niveau,son=1,quitter;
//######################### LA FOCTION MAIN : #########################
int main(){
	niveau=1;
	principal_menu();
}

//######################### LES FOCTIONS : #########################
void principal_menu(){
	char ch;
	titres(0,0);
	new_printf("@SPrincipal menu : @GFrappez [1/2/3/4]\n\n");
	new_printf("@J1. @WJouer\n");
	new_printf("@J2. @WComment jouer?\n\n");
	new_printf("@J3. @WLe son : ");
	if(son==0) new_printf("@RNon-Actif\n\n");
	else if(son==1) new_printf("@VActif\n\n");

	new_printf("@J4. @WSortir\n");
	ch=getch();
	//Pour entrer seulement les caracteres '1','2','3','4','5' parmis les autres
    while(ch<'1' || ch>'6')
    {
    	if(son==1) printf("\a");
		ch=getch();
	}
    system("cls");

    switch(ch)
    {
        case '1': niveau_menu();
        break;
        case '2': guide();
        break;
        case '3':
        {
        	if(son==0) son=1;
        	else if(son==1) son=0;
        	principal_menu();
        }
        break;
        case '4': printf("Sortir...");
        break;
    }
}
void niveau_menu(){
	char ch;
	titres(0,0);
	new_printf("@SNiveau menu : @GFrappez [1/2/3/4]\n\n");
	new_printf("@J1. @WJouer au @Vniveau 1\n");
	new_printf("@J2. @WJouer au @Rniveau 2\n\n");
	new_printf("@J3. @WRetourner\n");
	new_printf("@J4. @WSortir\n");
	ch=getch();
	//Pour entrer seulement les caracteres '1','2','3','4' parmis les autres
    while(ch<'1' || ch>'5')
    {
    	if(son==1) printf("\a");
		ch=getch();
	}
    system("cls");

    switch(ch)
    {
        case '1':
        {
        	niveau=1;
			jeu();
		}
        break;
        case '2':
        {
        	niveau=2;
			jeu();
		}
        break;
        case '3': retourner(1);
        break;
        case '4': printf("Sortir...");
        break;
    }
}
void guide(){
	char t;
    titres(1,0);
    new_printf("@WLe joueur 1 entre un code de 5 chiffres. Le joueur 2 va essayer de trouver\n");
	new_printf("@Wce code en se basant sur le nombre des chiffres biens placés, mals placés\n");
    new_printf("@Wet ceux qui n'existent pas :\n");
    new_printf("@V[+] : @Wbien placé\n");
    new_printf("@R[-] : @Wmal placé\n");
    new_printf("@G[ ] : @Wn'existe pas\n\n");
    new_printf("@WLe jeu se compose de deux niveaux :\n");
    new_printf("@VNiveau 1 : @WLes deux joueurs ne peuvent pas répéter un nombre.\n");
    new_printf("@RNiveau 2 : @WLes deux joueurs peuvent répété un nombre seulement une fois.\n\n");
	new_printf("@JOption Joker : @WCette option n'est disponible qu'à partir de la 10ème tentative,\n");
	printf("Il va permettre le joueur 2 d'afficher un chiffre de joueur 1 de son choix.\n");
	printf("Quand le joueur 2 l'utilise, il va perdre 3 essais.\n\n");
	new_printf("@CNote : @WLe son veut dire qu'il est impossible de frapper un caractère.\n");

    t=getch();
    //Pour entrer seulement le caractere 'R' parmis les autres
    while(t!='R' && t!='r')
    {
    	if(son==1) printf("\a");
		t=getch();
	}
    retourner(1);
}

void jeu(){
	char t;
	quitter=0;
	
	//Inisialisation
	var[0]=0;
	var[1]=0;

    //Pour le joueur 1
    titres(2,1);
    essai=0;
	new_printf("\n@CNote : @WVous êtes au ");
	if(niveau==1) new_printf("@Vniveau 1@W, vous ne pouvez pas répéter un nombre !\n\n");
	else if(niveau==2) new_printf("@Rniveau 2@W, vous pouvez répéter un nombre deux fois !\n\n");
	new_printf("@WEntrez un code de 5 nombres : ");
	new_scan(0);
	
	if(quitter!=1)
	{
		//Pour le joueur 2
		titres(2,2);
		essai=1;
		while(essai<=20 && var[0]!=5 && quitter==0){
			if(essai==10){
				new_printf("\n\n@CNote : @WOption Joker est déverrouillée, vous pouvez maintenant l'utiliser !\n");
				new_printf("@VFrappez J pour l'utiliser...\n");
			}
			if(essai>=10) utiliser_joker=0;
			new_printf("\n@WEssai "); printf("%d : ",essai);
			new_scan(1);
			
			if(essai<=20 && quitter==0) comp_affich();
			if(essai==20 && var[0]!=5 && quitter==0) resultat(0);
			if(var[0]!=5 && quitter==0) essai++;
		}
		
		if(quitter!=1)
		{
			if(essai<=20 && var[0]==5) resultat(1);	
			new_printf("\n\n@VPour rejouer le niveau "); printf("%d frappez E...\n",niveau);
		
			t=getch();
			//Pour entrer seulement Les caracteres 'E','e','N','n','R','r' parmis les autres
		    while(t!='E' && t!='e' && t!='N' && t!='n' && t!='R' && t!='r')
		    {
		    	if(son==1) printf("\a");
				t=getch();
			}
		
		    if(t=='E'||t=='e') retourner(0);
		    else if(t=='R'||t=='r') retourner(1);
		    else if(t=='N'||t=='n') retourner(2);
		}
	}
}
void titres(int etp,int j)
{
	if(etp==0){
		new_printf("\t\t@B===================================\n");
		new_printf("\t\t            @JMaster Mind\n");
		new_printf("\t\t@B===================================\n\n");
		new_printf("@CDevloppeur : @WOSSAMA ETTAQAFI\n\n");
	}
	else if(etp==1){
		new_printf("@VFrappez R pour retourner au principal menu...\n\n");
		new_printf("\t\t@B-----------------------------------\n");
		new_printf("\t\t@B| @SVoici le guide de : @JMaster Mind @B|\n");
		new_printf("\t\t@B-----------------------------------\n\n");
	}else if(etp==2){
		if(j==1){
			new_printf("@VFrappez R pour retourner au principal menu...\n");
			new_printf("@VFrappez N pour rechoisir le niveau...\n");
			new_printf("@VFrappez S pour abandonner...\n\n");
		}
		new_printf("\n\t\t@B------------------------------\n");
		new_printf("\t\t@B|          @J"); printf("Joueur %d ",j); new_printf("@B         |\n");
		new_printf("\t\t@B------------------------------\n");	
	}
}
void new_scan(int j){
	char t;
	int i,k;
	i=0;
	
	while(i<6){
	   	t=getch();
	   	//Entrer seulement les caracteres '0'..'9','R','r','N','n','J','j','S','s',ENTER,DELETE parmis les autres
	   	while(('0'>t || t>'9') && t!='R' && t!='r' && t!='N' && t!='n' && t!='J' && t!='j' && t!='S' && t!='s' && t!=13)
	   	{
	   		if(son==1 && t!=8) printf("\a");
	   		//Permet de suprimer un nombre quand on frappe DELETE
	   		if(t==8 && i>0){
	   			printf("\b \b");
				i--;
			}
		   	t=getch();
		}
		
		//Vérification si il trouve un nombre repeter à chaque niveau
		while(0<i && niveau==1?verifier(t,i,j)==1:verifier(t,i,j)==2)
		{
			if(son==1) printf("\a");	
			t=getch();
			//Entrer seulement les caracteres '0'..'9','R','r','N','n','J','j','S','s',ENTER,DELETE parmis les autres
			while(('0'>t || t>'9') && t!='R' && t!='r' && t!='N' && t!='n' && t!='J' && t!='j' && t!='S' && t!='s' && t!=13){
				if(son==1 && t!=8) printf("\a");	
				//Permet de suprimer un nombre quand on frappe DELETE
   				if(t==8 && i>0){
   					printf("\b \b");
					i--;
				}	
				t=getch();
			}
		}	
		
		if(t=='R'||t=='r') 
		{			
			retourner(1);
			//Pour sortir de la fonction jeu()
			quitter=1;
			//Pour sortir de la fonction new_scan()
			i=6;
		}
		else if(t=='N'||t=='n') 
		{
			retourner(2);
			//Pour sortir de la fonction jeu()
			quitter=1;
			//Pour sortir de la fonction new_scan()
			i=6;	
		}
		else if((t=='S'||t=='s') && essai!=0)
		{
			resultat(2);
			//Pour sortir de la boucle des essais qui se trouve dans la fonction jeu()
			quitter=2;
			//Pour sortir de la fonction new_scan()
			i=6;
		}
		else if((t=='J'||t=='j') && essai>=10 && essai<18 && utiliser_joker==0) jok(i);
		else if((t==13 || ('0'<=t && t<='9')) && i==5) i=6;
		
		if(t!='R'&& t!='r'&& t!='S' && t!='s' && t!='J'&& t!='j' && t!=13 && t!=8 && i<6){		
			new_printf("@J");
			if(j==0) printf("*"); 			//Le caractere saisi sera afficher sous forme d'une etoile *
			else if(j==1) printf("%c",t); 	//Le caractere saisi sera afficher
			
			Joueur[j][i]=t; 		 		//Placer le caractere dans une matrice (j ligne) (i colonne)

			i++;
	  	}
		if((t=='S' || t=='s' || t=='J' || t=='j') && essai==0)
		{
			if(son==1) printf("\a");
		}
	}
}
void comp_affich(){
	int i,k,touver;
	var[0]=0;  //bien placé
	var[1]=0;  //mal placé
	var[2]=5;  //n'existe pas

	int deja_comp[5]={0,0,0,0,0};

	//Comparaison
	for(i=0;i<5;i++){
		k=0;
		touver=0;
		while (k<5 && touver!=1){
			if(Joueur[0][k]==Joueur[1][i] && deja_comp[k]==0){
					if(k==i){
						var[0]++;
						var[2]--;
					}
					else{
						var[1]++;
						var[2]--;
					}
					touver=1;
					deja_comp[k]=1;
			}
		k++;
		}
	}
	
	//Affichage
	printf(" ");
	for(k=0;k<3;k++){
		for(i=0;i<var[k];i++){
		   if(k==0) new_printf("@V[+]"); 	    	//bien placé
		   else if(k==1) new_printf("@R[-]");   	//mal placé
		   else if(k==2) new_printf("@G[ ]");   	//n'existe pas
		}
	}
}
void resultat(int r){
	int i;
	if(r==0) new_printf("\n\n@RVous avez échouer, le code est : ");
	else if(r==1) new_printf("\n\n@VBravo, vous avez trouvez le code : ");
	else if(r==2) new_printf("\n\n@CVous avez abandonner, le code est : ");

	//Affichage de code du joueur 1
	new_printf("@J");
	for(i=0;i<5;i++) printf("%c",Joueur[0][i]);
}
void retourner(int r){
	system("cls");
	if(r==0) jeu();
	else if(r==1) principal_menu();
	else if(r==2) niveau_menu();
}
int verifier(char t,int v,int j){
	int i,rep;
	i=0;
	rep=0;
	while(i<v && (niveau==1?rep<=0:rep<=1))
	{
		if(t==Joueur[j][i]) rep+=1;
		i++;
	}
	return rep;
	//Si le nombre est déja trouver dans le code au niveau 1, il retourne 1 (le nombre de répétition)
	   //Sinon il retourne 0
	//Si les deux nombres sont deja trouver dans le code au niveau 2, il retourne 2 (le nombre de répétition)
	   //Sinon il retourne 0 ou 1
}
void jok(int i){
	char ch;
	int k;
	new_printf("\n\n@SJoker menu : @GFrappez [1/2/3/4/5/6]\n");
	new_printf("@WVous avez ces choix, dans "); printf("l'essai %d.\n\n",essai);
	new_printf("@J1. @WAfficher le 1er nombre\n");
	new_printf("@J2. @WAfficher le 2ème nombre\n");
	new_printf("@J3. @WAfficher le 3ème nombre\n");
	new_printf("@J4. @WAfficher le 4ème nombre\n");
	new_printf("@J5. @WAfficher le 5ème nombre\n\n");
	new_printf("@J6. @WAnnuler\n");

	ch=getch();
	//Pour entrer seulement les caracteres '1','2','3','4','5','6' parmis les autres
	while(ch<'1' || ch>'6')
	{
		if(son==1) printf("\a");
		ch=getch();
	}

	for(k=0;k<12;k++){
		printf("\x1b[A");
		printf("\33[2K\r");
	}
	switch(ch){
		case '1':
		{
			new_printf("@CLe 1er nombre est : @J"); printf("%c",Joueur[0][0]);
			utiliser_joker=1;
		}
		break;
		case '2':
		{
			new_printf("@CLe 2ème nombre est : @J"); printf("%c",Joueur[0][1]);
			utiliser_joker=1;
		}
		break;
		case '3':
		{
			new_printf("@CLe 3ème nombre est : @J"); printf("%c",Joueur[0][2]);
			utiliser_joker=1;
		}
		break;
		case '4':
		{
			new_printf("@CLe 4ème nombre est : @J"); printf("%c",Joueur[0][3]);
			utiliser_joker=1;
		}
		break;
		case '5':
		{
			new_printf("@CLe 5ème nombre est : @J"); printf("%c",Joueur[0][4]);
			utiliser_joker=1;
		}
		break;
		case '6': utiliser_joker=0;
		break;
	}
	if(ch>='1'&&ch<='5') printf("\n");
	new_printf("@WEssai "); printf("%d : ",essai); new_printf("@J");
	
	//Affichage du code de joueur 2 dans quel il arrete
	for(k=0;k<i;k++) printf("%c",Joueur[1][k]);

	if(utiliser_joker==1) essai=essai+3;
}
//Fonction de coleurs, elle permet de changer les coleurs de chaque caractère après @R,@B...
/* 
   @R: ROUGE 
   @B: BLEU 
   @V: VERT 
   @C: BLEU CIEL (CYAN)
   @W: BLANC 
   @J: JAUNE
   @S: ROSE
   @G: GRIS
*/
void new_printf(char text[])
{
	int t,i,k;
	t=strlen(text);
			
	i=0;

	while(i<t){
		if(text[i]=='@' && text[i+1]=='R') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		else if(text[i]=='@' && text[i+1]=='B') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
		else if(text[i]=='@' && text[i+1]=='V') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		else if(text[i]=='@' && text[i+1]=='C') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		else if(text[i]=='@' && text[i+1]=='W') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		else if(text[i]=='@' && text[i+1]=='G') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		else if(text[i]=='@' && text[i+1]=='J') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		else if(text[i]=='@' && text[i+1]=='S') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
		if(text[i]=='@') i+=2;
				
		k=i;
			
		while(text[k]!='@' && k<t)
		{
			if(text[k]=='é') printf("%c",130);		
			else if(text[k]=='è') printf("%c",138);		
			else if(text[k]=='à') printf("%c",133);	
			else if(text[k]=='ê') printf("%c",136);	
			else printf("%c",text[k]);		
			k++;
		}		
		i=k;	
	}
}

