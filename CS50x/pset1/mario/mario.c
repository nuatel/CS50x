#include <cs50.h>
#include <stdio.h>

void draw(int n, string s);

int main(void)
{
    // Prompt for height in range 1 - 8
    // h is the hight variable
    // t is number of heigh after loop 
    int h;
    int t;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Draw Mario : using loop for
    for (int i = 1; i <= h; i++)
    {
        t = h - i;
        draw(t, " ");
        draw(i, "#");
        draw(2, " ");
        draw(i, "#");
        printf("\n");
    }
}
// Dramw function
void draw(int n, string s)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", s);
    }
}