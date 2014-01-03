#include <string>
#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
using namespace std;

void create_figure(string& cmd, vector<string>& cmd_split, Dessin& dessin, string& figure_name )
{
    Figure* figure = new Figure( cmd_split[2] ); // TODO adapter en fonction du type de figure
    figure_name = cmd_split[1];
    dessin->Add(figure_name, figure);
}

int main()
{
    Dessin* dessin = new Dessin();
    string cmd;
    string figure_name;
    vector<string> cmd_split;



    for( ;; )
    {
        cin >> cmd;
        cmd_split = split(cmd, ' ');
        cmd = cmd_split[0];

        if( cmd.compare("EXIT") )
            { break; }
        if( cmd.compare("LOAD") )
            { dessin->Load( cmd_split[1] ); }
        else
            { create_figure(cmd, cmd_split, dessin, figure_name); }
    }

    return 0;
}
