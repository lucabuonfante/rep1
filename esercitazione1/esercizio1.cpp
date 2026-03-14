#include <fstream>
int main(int argc, char *argv[]){
    std::string nomefile="input_es1";
    std::ifstream lettore(nomefile); //gli dico da dove prendere i file
    if ( lettore.is_open() ) {  //se il file è aperto
        while( !lettore.eof() ) { //finché il puntatore lettore non arriva alla fine del file
            int t=0;
            while (t<=4) { //ciclo sulle colonne
                double t1=0; 
                double t2=0;
                double t3=0;
                double t4=0;
                std::string citta
                lettore >> citta >> t1 >> t2 >>t3 >> t4; //salvo l'informazione che mi viene dal lettore nelle variabili
                tmedia=(t1 + t2 + t3 + t4)/4;
                std::cout << citta << tmedia; // stampa prima la città poi la temp media
                t=t+1;
            }
        }
    }
}
