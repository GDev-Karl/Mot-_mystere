#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string melange(string motMystere);
int Aleatoire(int nbre_max);
string  piochemot();

int main()
{ 
    string mot_myster,mot_melanger, mot;
    char rep;
    string ligne;

    
    do
    {
        mot_myster = piochemot();
        //cout << mot_myster <<endl;
        mot_melanger = melange(mot_myster);

        int pts(5);
        while (1)
        {
            cout << endl << mot_melanger << endl <<" Quel est le mot mystere : " << endl;
            cin >> mot;

            for(int i = 0; i < mot.size(); i++)
                mot[i] = toupper(mot[i]);

            if (mot == mot_myster)
            {
                cout <<"Vous avez trouvez le mot bravo !" << endl;
                break;
            }   
            else
            {
                pts--;
                cout <<"Ce n'est pas le mot mystere" << endl <<"Il vous reste " << pts <<" points \n" << endl;
            }

            if(pts == 0)
            {
                cout <<"Fin du jeu le mot etait : " << mot_myster << endl;
                break;
            }
                
        }
        cout << "Voulez vous rejouer la partie ? (o/n)";
        cin >> rep;
        rep = toupper(rep);
    } while (rep == 'O');

    return 0;
}

string melange(string motMystere) // melanche les lettres des du motMystere
{
    string word;
    int position, i(0);

    while(motMystere.size() != 0)
    {
        position = Aleatoire(motMystere.size());

        word += motMystere[position];

        //cout << "Lettre au hasard :" << motMystere[position] << endl;

        motMystere.erase(position, 1);
        
        //cout << motMystere << endl;
        i++;
    }
    return word;
}

int Aleatoire(int nbre_max) // genere un nombre aleatoire a de 0 a nbre_max
{
    int nbre;
    srand(time(0));
    nbre = rand() % nbre_max;
    return nbre;
}

string  piochemot() // choisit un mot au hasard dans le dictionnaire
	{
		int nbre_mot(0),num_mot;
		string mot_cache;
		string const dict("dict.txt");
		ifstream flux(dict.c_str());

		if (flux)
		{
			char a;
			while(flux.get(a)) // Tant qu'on peut lire un caractere dans le fichier
			{	
				if(a == '\n')
					nbre_mot += 1;
			}
			num_mot = Aleatoire(nbre_mot);
		}
		else
			cout<<"Erreur";
		flux.close();
		flux.open(dict.c_str());

		if (flux){
			string ligne;
			while(num_mot >= 0)
			{
				while(getline(flux,ligne)){// tant qu'on peut lire une ligne dans le fichier
					mot_cache = ligne;
					num_mot--;
					break;
				}
			}
		}
		else
			cout<<"echouer";
		return mot_cache;
	}

