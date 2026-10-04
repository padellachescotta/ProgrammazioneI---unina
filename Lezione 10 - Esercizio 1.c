#include <stdio.h>
#include <math.h>

#define TARIFFA 1.80
#define COSTO_SERVIZIO 1.50

/*

Un parcheggio applica una tariffa di 1,80 € per ogni mezz’ora di sosta iniziata, oltre a un costo fisso di 
servizio di 1,50 €.
-Acquisire orario di ingresso e uscita, entrambi in ore e minuti.
-Assumere ingresso e uscita nella stessa giornata, con uscita successiva all’ingresso.
-considero una tariffa di 1,80 € anche se sono stato per meno di mezz’ora, cioè 1 minuto o 30 minuti, vale 
sempre 1,80€.
-Stampare una ricevuta con durata, intervalli, costo della sosta, costo di servizio e totale.

*/

void calcolo_ricevuta(float ingresso, float uscita, float risultati[4]){

    float durata;
    float ingresso_decimale = (int) ingresso + (((ingresso - (int) ingresso)*100)/60);
    float uscita_decimale = (int) uscita + (((uscita - (int) uscita)*100)/60);
    float conto_sosta, conto_servizio, conto;


    if(ingresso_decimale > uscita_decimale){
        durata = (24-ingresso_decimale) + uscita_decimale;
    }else{
        durata = uscita_decimale - ingresso_decimale;
    }

    conto_sosta = TARIFFA * ((int) ceil(durata/0.5));
    conto_servizio = COSTO_SERVIZIO * ((int) ceil(durata/0.5));
    conto = conto_sosta+conto_servizio;

    risultati[0] = conto_sosta;
    risultati[1] = conto_servizio;
    risultati[2] = conto;
    risultati[3] = durata;

}

void stampa_ricevuta(float risultati[4]){

    char formati[4][22] = {

        "conto sosta, euro ",
        "conto servizio, euro ",
        "conto totale, euro ",
        "durata, ore/minuti "

    };

    for(int i=0; i<4; i++){

        printf("%s, %.2f\n", formati[i], risultati[i]);

    }

}

int main(){

    float ingresso, uscita;
    float risultati[4];
    
    printf("Inserire ingresso e uscita dal parcheggio (formato: ore.minuti)");
    if (scanf("%f %f", &ingresso, &uscita) == 2) {
        calcolo_ricevuta(ingresso, uscita, risultati);
        stampa_ricevuta(risultati);
    } else {
        printf("Errore nell'inserimento dei dati.\n");
    }

    return 0;

}