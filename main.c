#include  <stdio.h>
#define SIZE 8
struct desk set_default_desk();
void display_desk(struct desk new);
struct desk change_desk(struct desk new_desk,  int x ,  int y, int new_x, int new_y);
int check_win(struct desk new_desk);

struct desk
{
    char desk[SIZE][SIZE];
    int pos[SIZE][SIZE];
    
};







/*const int one_use[SIZE] = {0,2,4,6}; */
/*const int two_use[SIZE] = {1,3,5,7}; */


int main(void)
{
   
    struct desk newdesk;
    int c_x, c_y, c_x_g, c_y_g; 
    int winner = 3;
    newdesk = set_default_desk();
    display_desk(newdesk);
    while(winner  == 3)
    { 
        printf("\nChose coord x:  ");
        scanf("%d", &c_x);
        printf("\nChose coord y: ");
        scanf("%d", &c_y);
        printf("\nChose coord x_g: ");
        scanf("%d", &c_x_g);
        printf("\nChose coord y_g: ");
        scanf("%d", &c_y_g);
        newdesk = change_desk(newdesk, c_x , c_y,c_x_g, c_y_g); 
        printf("\n");
        display_desk(newdesk);
        winner = check_win(newdesk);
    }
  
    return 0;
}


struct desk set_default_desk()
{
    int col = 1;
    struct desk funcdesk;
    for (size_t i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(i % 2 != 0)
            {
                if(i == 3)
                {
                    funcdesk.desk[i][j] = '#';
                }
                else
                {
                  if(i < 3)
                  { 
                    if(j % 2 == 0)
                        funcdesk.desk[i][j] = 'o';
                     else
                        funcdesk.desk[i][j] = '#';
                  } 
                  else
                  {
                    if(j % 2 == 0)
                        funcdesk.desk[i][j] = '0';
                     else
                        funcdesk.desk[i][j] = '#';
                  } 
                
                }
            }
            if(i%2 == 0)
            {
                if(i == 4)
                {
                    funcdesk.desk[i][j] = '#';
                }
                else
                {
                    if(i < 3) 
                    { 
                        if(j % 2 == 0)
                            funcdesk.desk[i][j] = '#';
                        else
                            funcdesk.desk[i][j] = 'o';  
                    }
                    else
                    {
                        if(j % 2 == 0)
                            funcdesk.desk[i][j] = '#';
                        else
                            funcdesk.desk[i][j] = '0';  
                    }
                }
            }
            
        }
        
    }
    return funcdesk;
}

void display_desk(struct desk new)
{
    printf("01234567\n"); 
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", new.desk[i][j]);
        }
        printf(" %d", i);
        printf("\n");
    }
}



struct desk change_desk(struct desk new_desk, int x, int y , int new_x, int new_y)
{
    if( (x % 2 == 0 && new_x % 2 != 0)  || (x%2 != 0 && new_x % 2 == 0) )
    {
        if(new_desk.desk[y][x] != '#')
        { 
            if(new_y - y == 1 ||  y - new_y == 1)
            { 
                struct desk funcdesk = new_desk; 
                new_desk.desk[new_y][new_x] = funcdesk.desk[y][x];
                new_desk.desk[y][x] = '#';
            }
        } 
    } 
    return new_desk;
}

int check_win(struct desk new_desk)
{
    int win = 3;
    int one_count = 0;
    int two_count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(new_desk.desk[i][j] == 'o')
               one_count++;
            if(new_desk.desk[i][j] == '0')
                two_count++;
        }
        
    } 
    if(one_count == 0)
        win = 2;
    if(two_count == 0)
        win = 1;

    return win;

}
