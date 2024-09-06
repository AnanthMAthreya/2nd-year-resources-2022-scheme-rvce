#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef;
    int power;
    struct node *link;
};

struct node *add_node(int c, int p, struct node *poly)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->coef = c;
    new->power = p;
    new->link = NULL;
    if (poly == NULL)
    {
        poly = new;
    }
    else
    {
        struct node *temp;
        temp = poly;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    return poly;
}

void display(struct node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coef, poly->power);
        if (poly->link != NULL)
            printf(" + ");
        poly = poly->link;
    }
}
struct node *add(struct node *poly1, struct node *poly2, struct node *result)
{
    struct node *t1;
    struct node *t2;
    t1 = poly1;
    t2 = poly2;
    int c, p;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->power == t2->power)
        {
            c = t1->coef + t2->coef;
            p = t1->power;
            t1 = t1->link;
            t2 = t2->link;
        }
        else if (t1->power > t2->power)
        {
            c = t1->coef;
            p = t1->power;
            t1 = t1->link;
        }
        else
        {
            c = t2->coef;
            p = t2->power;
            t2 = t2->link;
        }
        result = add_node(c, p, result);
    }
    // this is needed if there are unequal number of terms
    while (t1 != NULL)
    {
        c = t1->coef;
        p = t1->power;
        t1 = t1->link;
        result = add_node(c, p, result);
    }
    while (t2 != NULL)
    {
        c = t2->coef;
        p = t2->power;
        t2 = t2->link;
        result = add_node(c, p, result);
    }

    return result;
}

int main()
{
    struct node *p1 = NULL, *p2 = NULL, *result_add = NULL;
    printf("Enter coefficient and power for polynomial 1\n");
    int c, p;
    while (1)
    {
        scanf("%d %d", &c, &p);
        if (p == -1)
            break;
        p1 = add_node(c, p, p1);
    }
    printf("Enter coefficient and power for polynomial 2\n");
    while (1)
    {
        scanf("%d %d", &c, &p);
        if (p == -1)
            break;
        p2 = add_node(c, p, p2);
    }
    printf("Polynomial1: ");
    display(p1);
    printf("\nPolynomial2: ");
    display(p2);
    result_add = add(p1, p2, result_add);
    printf("initial result is \n");
    display(result_add);

    printf("\nFinal Polynomial after addition: ");
    display(result_add);
}

// 1 1 2 2 3 3 - 1 - 1
// 3 3 4 4 1 1 - 1 - 1
