// A program for building a rocket based on different user inputs, using void functions
// Project 1
// Programmer Name: Matthew Woody
#include <iostream>
using namespace std;

// function prototypes, nothing defined above main
// my functions are divided into each part of the rocket being even or odd, alleviating some of the work of determining choosing even or odd pieces
void drawRocketHollowConeOdd(int moduleWidth);
void drawRocketFilledConeOdd(int moduleWidth);
void drawOddFilledRocketModule(int moduleHeight,int moduleWidth);
void drawOddEmptyRocketModule(int moduleHeight,int moduleWidth);
void drawRocketHollowConeEven(int moduleWidth);
void drawRocketFilledConeEven(int moduleWidth);
void drawEvenFilledRocketModule(int moduleHeight, int moduleWidth);
void drawEvenEmptyRocketModule(int moduleHeight, int moduleWidth);
void drawStaticBoosters(); // did not include a parameter since no variables are a part of the function, just cout statements
void getRocketSpecs(int &moduleWidth, int &moduleHeight, int &numModules, char &moduleSpace);

int main()
{
    char again = 'y'; // initiailized so that do while loop will run at least once without user input
    int moduleHeight;
    int moduleWidth;
    int numModules; 
    char moduleSpace; 

do
{
  cout << "---------------------------------------------------------" << endl;
  cout << "SHAPE BUILDER SPECIFICATION REQUEST:" << endl;
  cout << "---------------------------------------------------------\n\n"; 
    getRocketSpecs(moduleHeight,moduleWidth,numModules,moduleSpace);


  // if statement to determine if the inputs are valid
    if ((moduleHeight >= 5 && moduleHeight <= 10) && (moduleWidth >= 10 && moduleWidth <= 15) && (numModules >= 2 && numModules <= 5) && (moduleSpace == 'E' || moduleSpace == 'e' || moduleSpace == 'F' || moduleSpace == 'f'))
      // more if statements to determine which rocket should be printed
    {

        // prints rocket with odd width and height, filled modules and hollow cone
        if((moduleHeight %2 != 0) && (moduleWidth %2 != 0) && (moduleSpace == 'F' || moduleSpace == 'f'))
        {
                drawRocketHollowConeOdd(moduleWidth);
                for (int l = 1; l <= numModules; l++)
                {         drawOddFilledRocketModule(moduleHeight,moduleWidth);
                }
                drawStaticBoosters();
        }

        // printing rocket with odd width and height, empty modules and filled cone
        if((moduleHeight %2 != 0) && (moduleWidth %2 != 0) && (moduleSpace == 'E'|| moduleSpace == 'e'))
        {
            drawRocketFilledConeOdd(moduleWidth);
            for (int l =1;l<=numModules; l++)
            {
      drawOddEmptyRocketModule(moduleHeight,moduleWidth);
            }
            drawStaticBoosters();
        }

        // printing rocket with even width and height, empty modules and filled cone
        if((moduleHeight %2 == 0) && (moduleWidth %2 == 0) && (moduleSpace == 'E'|| moduleSpace == 'e'))
        {
            drawRocketFilledConeEven(moduleWidth);
            for (int q =1;q<=numModules;q++)
            {
            drawEvenEmptyRocketModule(moduleHeight, moduleWidth);
            }
            drawStaticBoosters();
}

        // printing rocket with even width and height, filled modules and hollow cone
        if((moduleHeight %2 == 0) && (moduleWidth %2 == 0) && (moduleSpace == 'f'|| moduleSpace == 'F'))
        {
            drawRocketHollowConeEven(moduleWidth);
            for (int q =1;q<=numModules;q++)
            {
    drawEvenFilledRocketModule(moduleHeight,moduleWidth);
            }
            drawStaticBoosters();
        }

        // printing rocket with even height and odd witdh, filled modules and hollow cone
        if((moduleHeight %2 == 0) && (moduleWidth %2 != 0) && (moduleSpace == 'F'|| moduleSpace == 'f'))
        {
            drawRocketFilledConeOdd(moduleWidth);
            for (int l =1;l<=numModules; l++)
            {
            drawEvenFilledRocketModule(moduleHeight, moduleWidth);
            }
            drawStaticBoosters();
        }

        // printing a module with even moduleHeight, odd moduleWidth and empty modules with filled
        if((moduleHeight %2 == 0) && (moduleWidth %2 != 0) && (moduleSpace == 'E'|| moduleSpace == 'e'))
        {
            drawRocketFilledConeOdd(moduleWidth);
            for (int l =1;l<=moduleSpace; l++)
            {
    drawEvenEmptyRocketModule(moduleHeight,moduleWidth);
            }
            drawStaticBoosters();
        }

        // printing rocket with odd height and even width, filled modules and hollow cone
        if((moduleHeight %2 != 0) && (moduleWidth %2 == 0) && (moduleSpace == 'F'|| moduleSpace == 'f'))
        {
            drawRocketHollowConeEven(moduleWidth);
            for (int l = 1; l <= numModules; l++)
            {
    drawOddFilledRocketModule(moduleHeight,moduleWidth);
            }
            drawStaticBoosters();
        }

        // printing rocket with odd height and even width, empty modules and filled cone
        if((moduleHeight %2 != 0) && (moduleWidth %2 == 0) && (moduleSpace == 'E'|| moduleSpace == 'e'))
        {
            drawRocketFilledConeEven(moduleWidth);
            for (int l = 1; l <= numModules; l++)
            {
    drawOddEmptyRocketModule(moduleHeight,moduleWidth);
            }
            drawStaticBoosters();
        }
    }

cout << "\n\n---------------------------------------------------------" << endl;
    cout << " Try the ROCKET BUILD pattern generating algorithms again?" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Type 'Y' for yes or 'N' for no: ";
cin >> again;

}while(again == 'Y' || again =='y');

  // when user decides to quit, program ends
  cout << "\Now exiting the rocket build program ...." << endl;
return 0;

}
void drawRocketHollowConeOdd(int moduleWidth) // function to draw a hollow cone of odd width
{
    for(int j=1;j<=moduleWidth;j+=2) // variables can be whatever here since they will only be defined locally, in this function, and we can even use the same variables in the next function
    {
        for(int i=1;i<=(moduleWidth-j)/2;i++)
        {
        cout<<" ";
        }
        cout<<"*";
            if(j>1)
            {
                for(int h=1; h<=j-2; h++)
                {
                cout <<" ";
                }
                cout<<"*";
            }
            cout<<endl;
    }
}
void drawRocketFilledConeOdd(int moduleWidth)
{
    for(int j=1;j<=moduleWidth;j+=2) // used the same variables as the hollow function because we can
    {
        for(int i=1;i<=(moduleWidth-j)/2;i++)
        {
        cout<<" ";
        }
        cout<<"*";
            if(j>1)
            {
                for(int h=1; h<=j-2; h++)
                {
                cout <<"*"; // only had to change this line from the hollow cone function so it would print a * instead of a space inside of the cone
                }
                cout << "*";
            }
            cout << endl;
    }
}
void drawOddFilledRocketModule(int moduleHeight,int moduleWidth)
{
    for (int k = 1; k <= moduleHeight; k++)
    {
        for(int m=1;m<=moduleWidth;m++)
        {
        cout << "*";
        }
        cout << endl;
    }
}
void drawOddEmptyRocketModule(int moduleHeight,int moduleWidth)
{
    for (int i = 0; i < moduleHeight; i++)
    {
        for (int j = 0; j < moduleWidth; j++)
        {
            if ((j == 0) || (j == moduleWidth - 1))
            {
            cout << "*";
            }
                else if ((i == 0) || (i == moduleHeight - 1))
                {
                cout << "*";
                }
                    else
                    {
                    cout << " ";
                    }
        }
        cout << endl;
    }
    }
void drawRocketHollowConeEven(int moduleWidth)
{
 for(int j=1; j <= moduleWidth / 2; j++)
    {
        for (int i = 1; i <= (moduleWidth / 2) - j; i++)
        {
        cout << " ";
        }
        cout<<"*";
            if (j >= 1)
            {
                for (int h = 1; h <= 2 * j - 2; h++)
                {
                cout << " ";
                }
                cout << "*";
            }
            cout << endl;
    }
}
void drawRocketFilledConeEven(int moduleWidth)
{
 for (int j = 1 ;j <= moduleWidth / 2; j++)
    {
        for (int i = 1;i <= (moduleWidth / 2) - j; i++)
        {
        cout << " ";
        }
        cout << "*";
            if (j >= 1)
            {
                for (int h = 1; h <= 2 * j - 2; h++)
                {
                cout << "*";
                }
                cout << "*";
            }
            cout << endl;
    }
}
void drawEvenFilledRocketModule(int moduleHeight, int moduleWidth)
{
  for (int k = 1; k <= moduleHeight;k++)
    {
        for(int m = 1; m <= moduleWidth;m++)
        {
        cout << "*";
        }
        cout << endl;
    }
}
void drawEvenEmptyRocketModule(int moduleHeight, int moduleWidth)
{
    for (int i = 0; i < moduleHeight; i++)
    {
        for (int j = 0; j < moduleWidth; j++)
        {
            if ((j == 0) || (j == moduleWidth - 1))
            {
            cout << "*";
            }
                else if ((i == 0) || (i == moduleHeight - 1))
                {
                cout << "*";
                }
                    else
                    {
                    cout << " ";
                    }
        }
        cout << endl;
    }
}
void drawStaticBoosters() 
{
  cout << "  *    *" << endl;
  cout << " ***  ***" << endl;
  cout << "*   **   *" << endl;
}

void getRocketSpecs(int &moduleHeight, int &moduleWidth , int &numModules, char &moduleSpace)
{
    cout << "Dimension#1: Enter Rocket module width(a number between 10-15): ";
    cin >> moduleWidth;
  while (moduleWidth < 10 || moduleWidth > 15)
    {
      cout << "Enter a number between 10 and 15: ";
      cin >> moduleWidth;
    }

    cout << "\nDimension#2: Enter Rocket module height(a number between 5-10): ";
    cin >> moduleHeight;
  while (moduleHeight < 5 || moduleHeight > 10)
    {
      cout << "Enter a number between 5 and 10: ";
      cin >> moduleHeight;
    }

    cout << "\nRocket build: Enter number of modules to dock together(a number between 2-5): ";
    cin >> numModules;
  while (numModules < 2 || numModules > 5)
    {
      cout << "Enter a number between 2 and 5: ";
      cin >> numModules;
    }

    cout << "\nRocket Payload: Enter empty or filled cargo space in module/s (E - empty or F - filled): ";
    cin >> moduleSpace;
}