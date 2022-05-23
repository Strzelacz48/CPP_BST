T node::maksimum(const T &a, const T &b)
{
return a < b ? b : a;
}
bst<T>()
{
    start=null;
}
// destruktor
~bst<T>()
{

}
bst<T>(const bst &bst) // konstruktor kopiujący
{

}
bst<T>(initializer_list<T>)//kostruktor z listą inicjalizującą
{
    start=new node(/pierwszy element listy/)
    start->funkcja(/reszta listy/)
}
bst<T>(bst &&tree) // konstruktor przenoszący
{
    switch(start,tree->start);
}
bst<T>& operator = (const bst<T> &bst); // przypisanie kopiujące
{

}
bst<T>& operator = (bst<T> &&bst); // przypisanie przenoszące
{
    switch(start,tree->start);
}
node<T>(T val)
{
    left=null;
    right=null;
    key=val;
    isleaf=true;
}
node(T val,node l,node r)
{
    left=l;
    right=r;
    key=val;
    isleaf=false;
}
void bst::add(T val)
{
    if(start==null)
    {
        start=new node(val);
    }
    else
        start->add(val);
    start=start.add(val);
}
void bst::rm(T val)
{
    start=start.rm(val);
}
bool bst::find(T val);
{
    start.find(val);
}
node node::*add(T key);
{
    if(maksimum(val,left->key)==val && maksimum(val,right->key)==right->key)
    {
        if(maksimum(val,key)==key)
        {
            left=new node(T val,left,null);
            return this;
        }
        else
        {
            right=new node(T val,null ,right);
            return this;
        }
    }
    else if(maksimum(val,left->key)==val && maksimum(val,right->key)==val)
    {
        right=this.add(val);
    }
    else if(maksimum(val,left->key)==left->key && maksimum(val,right->key)==right->key)
    {
        left=this.add(val);
    }
}
