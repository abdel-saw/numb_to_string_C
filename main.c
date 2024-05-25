#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/* structure qui va contenir la partie entiere du nombre entrer ainsi qu'une partie de la partie decimale
 a lire (exception faites des premiers zeros entrer apres la virgule)
 (voir commentaire de la fonction recuperer_nombre pour comprendre0)*/
typedef struct
{

    char * Billiards  ;
    char * Billions  ;
    char * Milliards ;
    char * Millions ;
    char * Milliers  ;
    char * Centaines  ;
    char * Billiardsv  ;
    char * Billionsv ;
    char * Milliardsv  ;
    char * Millionsv  ;
    char * Milliersv  ;
    char * Centainesv  ;
} Nombre ;

/*cette fonction recupere le nombre entrer par l'utilisateur
 on va declarer trois tableau dynamique
 -le premier contient tous les chiffres entrer
 avant la virgule si c'est un nombre a virgule soit T1 ce tableau
 -le deuxieme contiendra le caractere '*' autant de fois que des zeros
 seront entrer immediatemment apres la virgule soit T2 ce tableau exemple
 si on entre 15,0015 alors T2[]="**" s'il n'y a pas de zeros alors il sera vide
 -le troisieme tableau va contenir tous les chiffres entrer apres les zeros entrer immediatemment apres la virgule soit T3 ce tableau
 s'il n'y a pas de zeros immediatemment apres la virgule ce tableau va contenir les chiffres entrer apres la virgule
comme on veut lire jusqua'au billiard (18 chiffres) on va completer les tableaux T1 et T3 par autant de
zeros qu'il faut pour atteindre les 18 chiffres
exemple de lecture de nombre : on entre 145,00012
on aura T1[]="000000000000000145" , T2[]="***" ,T3[]="000000000000000012"
on utilise la fonction strcat de la bibliotheque string.h a divers niveaux pour concatener ces tableaux on aura en fin de compte
une chaine de la forme "000000000000000145***000000000000000012"*/

char * recuperer_nombre()
{
    char * nb1 = NULL, *nb2 = NULL, *nb3= NULL;
    int c, ne1=0,ne2=0,ne3=0;
// remplissage de nb1 contenant la partie entiere
    while (((c = getchar()) != ',') && (c   != '.'))
    {

        if( c != '\n')
        {
            nb1 = (char *)realloc(nb1,sizeof(char)*(ne1+1));
            nb1[ne1++] = c;
        }
        else
        {
            break;
        }
    }
    nb1 = (char *)realloc(nb1,sizeof(char)*(ne1+1));
    nb1[ne1] = '\0';

    int r1 = 18 - ne1,ne11=0;
    char * nb11 = NULL ;
//completion de nb1 par des zeros pour atteindre les 18 chiffres
//nb11 contient au debut les zeros
    while ( r1 > 0)
    {
        nb11 = (char *)realloc(nb11,sizeof(char)*(ne11+1));
        nb11[ne11++]='0';
        r1--;
    }
    nb11 = (char *)realloc(nb11,sizeof(char)*(ne11+1));
    nb11[ne11]='\0';

    strcat(nb11,nb1);// nb11 contient maintenant la concatenation de nb11 et nb1

// remplissage de nb2 contenant le caractere '*'
    if( (c == ',') ||( c == '.'))
    {

        while ((c = getchar()) == '0')
        {


            {
                nb2 = (char *)realloc(nb2,sizeof(char)*(ne2+1));
                nb2[ne2++] = '*';
            }

        }
        nb2 = (char *)realloc(nb2,sizeof(char)*(ne2+1));
        nb2[ne2--] = '\0';

        strcat(nb11,nb2);// a nb11 sera ajouter nb2
    }

// recuperation des chiffres entrer a la fin des zeros entrer immediatemment apres la virgule dans nb3
    while (c != '\n')
    {

        {
            nb3 = (char *)realloc(nb3,sizeof(char)*(ne3+1));
            nb3[ne3++] = c;
            c = getchar();
        }

    }
    nb3 = (char *)realloc(nb3,sizeof(char)*(ne3+1));
    nb3[ne3] = '\0';
// completion de nb3 par des zeros
//nb33 contient au debut les zeros
    int r2 = 18 - ne3,ne33=0;
    char * nb33 = NULL ;

    while ( r2 > 0)
    {
        nb33 = (char *)realloc(nb33,sizeof(char)*(ne33+1));
        nb33[ne33++]='0';
        r2--;
    }
    nb33 = (char *)realloc(nb33,sizeof(char)*(ne33+1));
    nb33[ne33]='\0';

    strcat(nb33,nb3);//nb33 contient la concatenation de nb33 et nb3

    strcat(nb11,nb33);//a nb11 on ajoute nb33 pour avoir la chaine finale retourner


    return nb11;




}

/*cette fonction permet de lire n caractere a partir de l'indice i dans la chaine de caractere chaine
et retourne la chaine constitue de ces n caractere*/

char * lire_n_caractere( int i, int n, char *chaine)

{
    char * ch3 = NULL ;
    int cpt = 0,ne3 = 0;

    while(cpt++ < n)
    {
        ch3 = (char*)realloc(ch3,sizeof(char)*(ne3+1));
        ch3[ne3++]=chaine[i++];
    }
    ch3 = (char*)realloc(ch3,sizeof(char)*(ne3+1));
    ch3[ne3]='\0';
    return ch3;
}

/* cette fonction recoit en parametre une chaine consitue de deux caractere
la compare aux caratere contenu de la fonction et retourne une chaine
 de caractere en fonction de la correspondance elle va permettre de lire les dizaines d'un nombre */

char * lire_dizaine(char *value)
{
    char * ch = NULL;



    if(strcmp(value,"01")== 0)
    {
        ch="Un";
        return ch;
    }
    if(strcmp(value,"02")== 0)
    {
        ch="Deux";
        return ch;
    }
    if(strcmp(value,"03")== 0)
    {
        ch="Trois";
        return ch;
    }
    if(strcmp(value,"04")== 0)
    {
        ch="Quatre";
        return ch;
    }
    if(strcmp(value,"05")== 0)
    {
        ch="Cinq";
        return ch;
    }
    if(strcmp(value,"06")== 0)
    {
        ch="Six";
        return ch;
    }
    if(strcmp(value,"07")== 0)
    {
        ch="Sept";
        return ch;
    }
    if(strcmp(value,"08")== 0)
    {
        ch="Huit";
        return ch;
    }
    if(strcmp(value,"09")== 0)
    {
        ch="Neuf";
        return ch;
    }
    if(strcmp(value,"10")== 0)
    {
        ch="Dix";
        return ch;
    }
    if(strcmp(value,"11")== 0)
    {
        ch="Onze";
        return ch;
    }
    if(strcmp(value,"12")== 0)
    {
        ch="Douze";
        return ch;
    }
    if(strcmp(value,"13")== 0)
    {
        ch="Treize";
        return ch;
    }
    if(strcmp(value,"14")== 0)
    {
        ch="Quatorze";
        return ch;
    }
    if(strcmp(value,"15")== 0)
    {
        ch="Quinze";
        return ch;
    }
    if(strcmp(value,"16")== 0)
    {
        ch="Seize";
        return ch;
    }
    if(strcmp(value,"17")== 0)
    {
        ch="Dix-Sept";
        return ch;
    }
    if(strcmp(value,"18")== 0)
    {
        ch="Dix-Huit";
        return ch;
    }
    if(strcmp(value,"19")== 0)
    {
        ch="Dix-Neuf";
        return ch;
    }
    if(strcmp(value,"20") == 0)
    {
        ch="Vingt";
        return ch;
    }
    if(strcmp(value,"21")== 0)
    {
        ch="Vingt-et-Un";
        return ch;
    }
    if(strcmp(value,"22")== 0)
    {
        ch="Vingt-Deux";
        return ch;
    }
    if(strcmp(value,"23")== 0)
    {
        ch="Vingt-Trois";
        return ch;
    }
    if(strcmp(value,"24")== 0)
    {
        ch="Vingt-Quatres";
        return ch;
    }
    if(strcmp(value,"25")== 0)
    {
        ch="Vingt-Cinq";
        return ch;
    }
    if(strcmp(value,"26")== 0)
    {
        ch="Vingt-Six";
        return ch;
    }
    if(strcmp(value,"27")== 0)
    {
        ch="vingt-Sept";
        return ch;
    }
    if(strcmp(value,"28")== 0)
    {
        ch="Vingt-Huit";
        return ch;
    }
    if(strcmp(value,"29")== 0)
    {
        ch="Vingt-Neuf";
        return ch;
    }
    if(strcmp(value,"30")== 0)
    {
        ch="Trente";
        return ch;
    }
    if(strcmp(value,"31")== 0)
    {
        ch="Trente-et-Un";
        return ch;
    }
    if(strcmp(value,"32")== 0)
    {
        ch="Trente-Deux";
        return ch;
    }
    if(strcmp(value,"33")== 0)
    {
        ch="Trente-Trois";
        return ch;
    }
    if(strcmp(value,"34")== 0)
    {
        ch="Trente-Quatres";
        return ch;
    }
    if(strcmp(value,"35")== 0)
    {
        ch="Trente-Cinq";
        return ch;
    }
    if(strcmp(value,"36")== 0)
    {
        ch="Trente-Six";
        return ch;
    }
    if(strcmp(value,"37")== 0)
    {
        ch="Trente-Sept";
        return ch;
    }
    if(strcmp(value,"38")== 0)
    {
        ch="Trente-Huit";
        return ch;
    }
    if(strcmp(value,"39")== 0)
    {
        ch="Trente-Neuf";
        return ch;
    }
    if(strcmp(value,"40")== 0)
    {
        ch="Quarante";
        return ch;
    }
    if(strcmp(value,"41")== 0)
    {
        ch="Quarante-et-Un";
        return ch;
    }
    if(strcmp(value,"42")== 0)
    {
        ch="Quarante-Deux";
        return ch;
    }
    if(strcmp(value,"43")== 0)
    {
        ch="Quarante-Trois";
        return ch;
    }
    if(strcmp(value,"44")== 0)
    {
        ch="Quarante-Quatres";
        return ch;
    }
    if(strcmp(value,"45")== 0)
    {
        ch="Quarante-Cinq";
        return ch;
    }
    if(strcmp(value,"46")== 0)
    {
        ch="Quarante-Six";
        return ch;
    }
    if(strcmp(value,"47")== 0)
    {
        ch="Quarante-Sept";
        return ch;
    }
    if(strcmp(value,"48")== 0)
    {
        ch="Quarante-Huit";
        return ch;
    }
    if(strcmp(value,"49")== 0)
    {
        ch="Quarante-Neuf";
        return ch;
    }
    if(strcmp(value,"50")== 0)
    {
        ch="Cinquante";
        return ch;
    }

    if(strcmp(value,"51")== 0)
    {
        ch="Cinquante-et-Un";
        return ch;
    }
    if(strcmp(value,"52")== 0)
    {
        ch="Cinquante-Deux";
        return ch;
    }
    if(strcmp(value,"53")== 0)
    {
        ch="Cinquante-Trois";
        return ch;
    }
    if(strcmp(value,"54")== 0)
    {
        ch="Cinquante-Quatres";
        return ch;
    }
    if(strcmp(value,"55")== 0)
    {
        ch="Cinquante-Cinq";
        return ch;
    }
    if(strcmp(value,"56")== 0)
    {
        ch="Cinquante-Six";
        return ch;
    }
    if(strcmp(value,"57")== 0)
    {
        ch="Cinquante-Sept";
        return ch;
    }
    if(strcmp(value,"58")== 0)
    {
        ch="Cinquante-Huit";
        return ch;
    }
    if(strcmp(value,"59")== 0)
    {
        ch="Cinquante-Neuf";
        return ch;
    }
    if(strcmp(value,"60")== 0)
    {
        ch="Soixante";
        return ch;
    }
    if(strcmp(value,"61")== 0)
    {
        ch="Soixante-et-Un";
        return ch;
    }
    if(strcmp(value,"62")== 0)
    {
        ch="Soixante-Deux";
        return ch;
    }
    if(strcmp(value,"63")== 0)
    {
        ch="Soixante-Trois";
        return ch;
    }
    if(strcmp(value,"64")== 0)
    {
        ch="Soixante-Quatres";
        return ch;
    }
    if(strcmp(value,"65")== 0)
    {
        ch="Soixante-Cinq";
        return ch;
    }
    if(strcmp(value,"66")== 0)
    {
        ch="Soixante-Six";
        return ch;
    }
    if(strcmp(value,"67")== 0)
    {
        ch="Soixante-Sept";
        return ch;
    }
    if(strcmp(value,"68")== 0)
    {
        ch="Soixante-Huit";
        return ch;
    }
    if(strcmp(value,"69")== 0)
    {
        ch="Soixante-Neuf";
        return ch;
    }
    if(strcmp(value,"70")== 0)
    {
        ch="Soixante-Dix";
        return ch;
    }
    if(strcmp(value,"71")== 0)
    {
        ch="Soixante-Onze";
        return ch;
    }
    if(strcmp(value,"72")== 0)
    {
        ch="Soixante-Douze";
        return ch;
    }
    if(strcmp(value,"73")== 0)
    {
        ch="Soixante-Treize";
        return ch;
    }
    if(strcmp(value,"74")== 0)
    {
        ch="Soixante-Quatorze";
        return ch;
    }
    if(strcmp(value,"75")== 0)
    {
        ch="Soixante-Quinze";
        return ch;
    }
    if(strcmp(value,"76")== 0)
    {
        ch="Soixante-Seize";
        return ch;
    }
    if(strcmp(value,"77")== 0)
    {
        ch="Soixante-Dix-Sept";
        return ch;
    }
    if(strcmp(value,"78")== 0)
    {
        ch="Soixante-Dix-Huit";
        return ch;
    }
    if(strcmp(value,"79")== 0)
    {
        ch="Soixante-Dix-Neuf";
        return ch;
    }
    if(strcmp(value,"80")== 0)
    {
        ch="Quatre-Vingts";
        return ch;
    }
    if(strcmp(value,"81")== 0)
    {
        ch="Quatre-Vingt-et-Un";
        return ch;
    }
    if(strcmp(value,"82")== 0)
    {
        ch="Quatre-Vingt-Deux";
        return ch;
    }
    if(strcmp(value,"83")== 0)
    {
        ch="Quatre-Vingt-Trois";
        return ch;
    }
    if(strcmp(value,"84")== 0)
    {
        ch="Quatre-Vingt-Quatres";
        return ch;
    }
    if(strcmp(value,"85")== 0)
    {
        ch="Quatre-Vingt-Cinq";
        return ch;
    }
    if(strcmp(value,"86")== 0)
    {
        ch="Quatre-Vingt-Six";
        return ch;
    }
    if(strcmp(value,"87")== 0)
    {
        ch="Quatre-Vingt-Sept";
        return ch;
    }
    if(strcmp(value,"88")== 0)
    {
        ch="Quatre-Vingt-Huit";
        return ch;
    }
    if(strcmp(value,"89")== 0)
    {
        ch="Quatre-Vingt-Neuf";
        return ch;
    }
    if(strcmp(value,"90")== 0)
    {
        ch="Quatre-Vingt-Dix";
        return ch;
    }
    if(strcmp(value,"91")== 0)
    {
        ch="Quatre-Vingt-et-Onze";
        return ch;
    }
    if(strcmp(value,"92")== 0)
    {
        ch="Quatre-Vingt-Douze";
        return ch;
    }
    if(strcmp(value,"93")== 0)
    {
        ch="Quatre-Vingt-Treize";
        return ch;
    }
    if(strcmp(value,"94")== 0)
    {
        ch="Quatre-Vingt-Quatorze";
        return ch;
    }
    if(strcmp(value,"95")== 0)
    {
        ch="Quatres-Vingt-Quinze";
        return ch;
    }
    if(strcmp(value,"96")== 0)
    {
        ch="Quatre-Vingt-Seize";
        return ch;
    }
    if(strcmp(value,"97")== 0)
    {
        ch="Quatre-Vingt-Dix-Sept";
        return ch;
    }
    if(strcmp(value,"98")== 0)
    {
        ch="Quatre-Vingt-Dix-Huit";
        return ch;
    }
    if(strcmp(value,"99")== 0)
    {
        ch="Quatre-Vingt-Dix-Neuf";
        return ch;
    }


}


/* cette fonction recoit en parametre une chaine de 3 caractere , la compare au contenu de la fonction et affiche
une chaine de caractere en fonctionde la correspondance , elle va nous permettre de lire les centaines d'un nombre*/
void lire_centaine( char * value)
{
    char *ch1=NULL;
    if(value[0] == '0')
    {
        ch1=lire_dizaine(lire_n_caractere(1,2,value));
        printf("%s",ch1);
        return;
    }
    if( value[0] == '1')
    {
        if( strcmp(value,"100") == 0)
        {
            printf("Cent ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Cent-%s",ch1);

        }
        return;
    }
    if( value[0] == '2')
    {
        if( strcmp(value,"200") == 0)
        {
            printf("Deux-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Deux-Cent-%s",ch1);
        }
        return;


    }
    if( value[0] == '3')
    {
        if( strcmp(value,"300") == 0)
        {
            printf("Trois-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Trois-Cent-%s",ch1);
        }
        return;

    }
    if( value[0] == '4')
    {
        if( strcmp(value,"400") == 0)
        {
            printf("Quatre-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Quatre-Cent-%s",ch1);
        }
        return;
    }
    if( value[0] == '5')
    {
        if( strcmp(value,"500") == 0)
        {
            printf("Cinq-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Cinq-Cent-%s",ch1);
        }
        return;

    }
    if( value[0] == '6')
    {
        if( strcmp(value,"600") == 0)
        {
            printf("Six-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Six-Cent-%s",ch1);
        }
        return;
    }
    if( value[0] == '7')
    {

        if( strcmp(value,"700") == 0)
        {
            printf("Sept-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Sept-Cent-%s",ch1);
        }
        return;
    }
    if( value[0] == '8')
    {

        if( strcmp(value,"800") == 0)
        {
            printf("Huit-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Huit-Cent-%s",ch1);
        }
        return;

    }
    if( value[0] == '9')
    {

        if( strcmp(value,"900") == 0)
        {
            printf("Neuf-Cents ");
        }
        else
        {
            ch1=lire_dizaine(lire_n_caractere(1,2,value));
            printf(" Neuf-Cent8-%s",ch1);
        }
        return;
    }
}

/* cette fonction permet d'afficher l'equivalent litteral d'un nombre entrer par
un utilisateur jusqu'au billiard , elle recoit en parametre la chaine issu de la fonction
recuperer nombre */

void lire_nombre( char * nombre)

/* on compte le nombre de zeros immediat entrer apres la virgule
en recherchant le nombre d'occurence du caractere '*' soit nbz ce nombre*/
{
    Nombre *Nbr = NULL;
    int nbz = 0,i;

    for(i=0; i< strlen(nombre); i++)
    {
        if(nombre[i]== '*')
            nbz++;
    }

/* on va ensuite remlir la strucrture de type Nombre creer , on
sait que les 18 premiers caracteres correspondent a la partie entiere
et que les caratere suivant seront '*' s'il y'a des zeros immediats qui sont entrer apres la virgule
on va ignorer ces caractere et stocker les caracteres suivant a partir de l'indice 18+nbz dans les differents
 element de la structure nombre
si nbz=0 alors ce n'est pas un nombre a virgule*/

    Nbr = (Nombre *)realloc(Nbr,sizeof(Nombre));

    Nbr->Billiards = lire_n_caractere(0,3,nombre);
    Nbr->Billions = lire_n_caractere(3,3,nombre);
    Nbr->Milliards = lire_n_caractere(6,3,nombre);
    Nbr->Millions = lire_n_caractere(9,3,nombre);
    Nbr->Milliers = lire_n_caractere(12,3,nombre);
    Nbr->Centaines = lire_n_caractere(15,3,nombre);
    Nbr->Billiardsv = lire_n_caractere(18+nbz,3,nombre);
    Nbr->Billionsv = lire_n_caractere(21+nbz,3,nombre);
    Nbr->Milliardsv = lire_n_caractere(24+nbz,3,nombre);
    Nbr->Millionsv = lire_n_caractere(27+nbz,3,nombre);
    Nbr->Milliersv = lire_n_caractere(30+nbz,3,nombre);
    Nbr->Centainesv = lire_n_caractere(33+nbz,3,nombre);

// on commence le test de lecture pour la partie entiere soit les 18 premiers elements de la chaine
    if(strcmp(Nbr->Billiards,"000") != 0)
    {
        if(strcmp(Nbr->Billiards,"001") == 0)
        {
            printf("Un Billiard ");
        }
        else
        {
            lire_centaine(Nbr->Billiards);
            printf(" Billiards ");

        }

    }

    if(strcmp(Nbr->Billions,"000") != 0)
    {
        if(strcmp(Nbr->Billions,"001") == 0)
        {
            printf("Un Billion ");
        }
        else
        {
            lire_centaine(Nbr->Billions);
            printf(" Billions ");

        }
    }

    if(strcmp(Nbr->Milliards,"000") != 0)
    {
        if(strcmp(Nbr->Milliards,"001") == 0)
        {
            printf("Un Milliard ");
        }
        else
        {
            lire_centaine(Nbr->Milliards);
            printf(" Milliards");
        }

    }

    if(strcmp(Nbr->Millions,"000") != 0)
    {
        if(strcmp(Nbr->Millions,"001") == 0)
        {
            printf("Un Million ");
        }
        else
        {
            lire_centaine(Nbr->Millions);
            printf(" Millions");
        }

    }

    if(strcmp(Nbr->Milliers,"000") != 0)
    {
        if(strcmp(Nbr->Milliers,"001") != 0)
        {
            lire_centaine(Nbr->Milliers);
            printf(" Mille ");
        }
        else
        {
            printf(" Mille ");
        }


    }

    if(strcmp(Nbr->Centaines,"000") != 0)
    {
        lire_centaine(Nbr->Centaines);

    }

// on verifie si le nombre est a virgule si c'est le cas on affiche le message 'virgule'
    if(strcmp(Nbr->Centainesv,"000") != 0 )
    {
        printf(" Virgule ");


    // on va afficher le message 'zeros' autant de fois qu'il y'en a qui on ete entre immediatement apres la virgule

    int l = 0;

    while(l < nbz)
    {
        printf("zero ");
        l++;
    }

    /* on commence le test de lecture des nombres entrer apres les zeros ou simplement
    des nombres apres la virgule s'il n'y a pas de zeros */

    if(strcmp(Nbr->Billiardsv,"000") != 0)
    {
        if(strcmp(Nbr->Billiardsv,"001") == 0)
        {
            printf("Un Billiard ");
        }
        else
        {
            lire_centaine(Nbr->Billiardsv);
            printf(" Billiards ");
        }

    }

    if(strcmp(Nbr->Billionsv,"000") != 0)
    {
        if(strcmp(Nbr->Billionsv,"001") == 0)
        {
            printf("Un Billion");
        }
        else
        {
            lire_centaine(Nbr->Billionsv);
            printf(" Billions ");
        }


    }


    if(strcmp(Nbr->Milliardsv,"000") != 0)
    {
        if(strcmp(Nbr->Milliardsv,"001") == 0)
        {
            printf("Un Milliard ");
        }
        else
        {
            lire_centaine(Nbr->Milliardsv);
            printf(" Milliards");
        }


    }


    if(strcmp(Nbr->Millionsv,"000") != 0)
    {
        if(strcmp(Nbr->Millionsv,"001") == 0)
        {
            printf("Un Million");
        }
        else
        {
            lire_centaine(Nbr->Millionsv);
            printf(" Millions");
        }




    }


    if(strcmp(Nbr->Milliersv,"000") != 0)
    {

        if(strcmp(Nbr->Milliersv,"001") != 0)
        {
            lire_centaine(Nbr->Milliersv);
            printf(" Mille ");
        }
        else
        {
            printf(" Mille ");
        }


    }


    if(strcmp(Nbr->Centainesv,"000") != 0)
    {

        lire_centaine(Nbr->Centainesv);

    }

    }



}

int main()
{
    char *nombre = NULL;
    printf("entrer le nombre : ");
    nombre = recuperer_nombre();
    lire_nombre(nombre);


}

