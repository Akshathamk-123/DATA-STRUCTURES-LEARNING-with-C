void init(ARRLST *pal)
{
    pal->index= -1;
}

int append(ARRLST *pal,int e)
{
    if(pal->index==MAX-1)
        return 0;
    pal->index++;
    pal->a[pal->index]=e;
}

int delLast(ARRLST *pal,int *ele)
{
    
}
