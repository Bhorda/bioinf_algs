#include <string>
#include <iostream>

int match(char v, char w)
{
    if (v == w) return 5;
    else return -3;
}

int nw(std::string v, std::string w)
{
    std::cout << "Needleman-Wunsch Algorithm:" << std::endl;
    std::cout << "Table: " << std::endl;

    int F[v.length()+1][w.length()+1];
    int d = -4;

    for (int i = 0; i < v.length()+1; i++)
    {
        F[i][0] = i * d;
    }
    for (int i = 0; i < w.length()+1; i++)
    {
        F[0][i] = i * d;
    }
    for (int i = 1; i < v.length()+1; i++)
    {
        for (int j = 1; j < w.length()+1; j++)
        {
            int s = match (v[i-1], w[j-1]);
            F[i][j] = std::max(F[i-1][j-1] + s, 
                    std::max(F[i][j-1] + d, F[i-1][j] + d));
        }
    }
    
    for (int i = 0; i < v.length()+1; i++)
    {
        for (int j = 0; j < w.length()+1; j++)
        {
            std::string s = " ";
            if (F[i][j] < 10) {
                if (F[i][j] > -1)
                {
                    std::cout << s << s << F[i][j] << s;
                }
                else if (F[i][j] > -10) 
                {
                    std::cout << s << F[i][j] << s;
                }
                else 
                {
                    std::cout << F[i][j] << s;
                }
            }
            else 
            {
                std::cout << s <<  F[i][j] << s;

            }        
        }
        std::cout << std::endl;
    }

    std::cout << "Alignment score: ";
    std::cout << F[v.size()][w.size()] << std::endl;

    return 0;
}

int main (int argc, char* argv[])
{
    std::string v = "GACTACC";
    std::string w = "CGTGAA";

    nw(v,w);

    return 0;
}
