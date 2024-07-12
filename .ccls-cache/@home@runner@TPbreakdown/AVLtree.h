#include <iostream>
#include<cctype>
#include <stdlib.h>


using namespace std;

struct nodeh
{
    int gajiBID;
    string NIP;
    string namaBidan;
    string jlnBidan;
    string rtBidan;
    string rwBidan;
    string kecBidan;
    string kabBidan;
    string desaBidan;
    string nikBidan;
    string provBidan;
    string tmptLahirBidan;
    string tglLahirBidan;
    string noHp;
    // double gajiBID;
    nodeh *left;
    nodeh *right;
    int height;
};
typedef struct nodeh *nodeptr;
class bstree
{
public:
    void insert(int,string, string, string , string, string , string ,string, string, string , string, string, string , string ,nodeptr &);
    void del(int, nodeptr &);
    int deletemin(nodeptr &);
    void find(int,nodeptr &);
    nodeptr findmin(nodeptr);
    nodeptr findmax(nodeptr);
    void makeempty(nodeptr &);
    void copy(nodeptr &,nodeptr &);
    nodeptr nodecopy(nodeptr &);
    void preorder(nodeptr);
    void inorder(nodeptr);
    void postorder(nodeptr);
    int bsheight(nodeptr);
    nodeptr srl(nodeptr &);
    nodeptr drl(nodeptr &);
    nodeptr srr(nodeptr &);
    nodeptr drr(nodeptr &);
    int max(int,int);
    int nonodes(nodeptr);
};
// Inserting a node
void bstree::insert(int x,string NIP, string nikBidan, string namaBidan,string provBidan,string tglLahirBidan, string tmptLahirBidan, string noHp,   string jlnBidan, string rtBidan , string rwBidan , string desaBidan, string kecBidan, string kabBidan,nodeptr &p)
{
    if (p == NULL)
    {
        p = new nodeh;
        p->gajiBID = x;
        p->NIP = NIP;
        p->nikBidan= nikBidan;
        p->namaBidan = namaBidan;
        p->provBidan = provBidan;
        p->tglLahirBidan= tglLahirBidan;
        p->tmptLahirBidan= tmptLahirBidan;
        p->noHp = noHp;
        p->jlnBidan =jlnBidan;
        p->rtBidan= rtBidan;
        p->rwBidan = rwBidan;
        p->desaBidan = desaBidan;
        p->kecBidan = kecBidan;
        p->kabBidan=kabBidan;
        p->left=NULL;
        p->right = NULL;
        p->height=0;
        if (p==NULL)
        {
            cout<<"Out of Space\n"<<endl;
        }
    }
    else
    {
        if (x<p->gajiBID)
        {
            insert(x,NIP,nikBidan,namaBidan,provBidan,tglLahirBidan,tmptLahirBidan,noHp,jlnBidan,rtBidan,rwBidan,desaBidan,kecBidan,kabBidan,p->left);
            if ((bsheight(p->left) - bsheight(p->right))==2)
            {
                if (x < p->left->gajiBID)
                {
                    p=srl(p);
                }
                else
                {
                    p = drl(p);
                }
            }
        }
        else if (x>p->gajiBID)
        {
            insert(x,NIP,nikBidan,namaBidan,provBidan,tglLahirBidan,tmptLahirBidan,noHp,jlnBidan,rtBidan,rwBidan,desaBidan,kecBidan,kabBidan,p->right);
            if ((bsheight(p->right) - bsheight(p->left))==2)
            {
                if (x > p->right->gajiBID)
                {
                    p=srr(p);
                }
                else
                {
                    p = drr(p);
                }
            }
        }
        else
        {
            cout<<"Element Exists\n"<<endl;
        }
    }
    int m,n,d;
    m=bsheight(p->left);
    n=bsheight(p->right);
    d=max(m,n);
    p->height = d + 1;
}
// Finding the Smallest
nodeptr bstree::findmin(nodeptr p)
{
    if (p==NULL)
    {
        cout<<"The tree is empty\n"<<endl;
        return p;
    }
    else
    {
        while(p->left !=NULL)
        {
            p=p->left;
            //return p;
        }
        return p;
    }
}
// Finding the Largest node
nodeptr bstree::findmax(nodeptr p)
{
    if (p==NULL)
    {
        cout<<"The tree is empty\n"<<endl;
        return p;
    }
    else
    {
        while(p->right !=NULL)
        {
            p=p->right;
            //return p;
        }
        return p;
    }
}
// Finding an gajiBID
void bstree::find(int x,nodeptr &p)
{
    if (p==NULL)
    {
        cout<<"Sorry! gajiBID not found\n"<<endl;
    }
    else
    {
        if (x < p->gajiBID)
        {
            find(x,p->left);
        }
        else
        {
            if (x>p->gajiBID)
            {
                find(x,p->right);
            }
            else
            {
                cout<<"Element found!\n"<<endl;
            }
        }
    }
}
// Copy a tree
void bstree::copy(nodeptr &p,nodeptr &p1)
{
    makeempty(p1);
    p1 = nodecopy(p);
}
// Make a tree empty
void bstree::makeempty(nodeptr &p)
{
    nodeptr d;
    if (p != NULL)
    {
        makeempty(p->left);
        makeempty(p->right);
        d=p;
        free(d);
        p=NULL;
    }
}
// Copy the nodes
nodeptr bstree::nodecopy(nodeptr &p)
{
    nodeptr temp;
    if (p==NULL)
    {
        return p;
    }
    else
    {
        temp = new nodeh;
        temp->gajiBID = p->gajiBID;
        temp->left = nodecopy(p->left);
        temp->right = nodecopy(p->right);
        return temp;
    }
}

// Deleting a node
void bstree::del(int x,nodeptr &p)
{
    nodeptr d;
    if (p==NULL)
    {
        cout<<"Sorry! gajiBID not found\n"<<endl;
    }
    else if ( x < p->gajiBID)
    {
        del(x,p->left);
    }
    else if (x > p->gajiBID)
    {
        del(x,p->right);
    }
    else if ((p->left == NULL) && (p->right == NULL))
    {
        d=p;
        free(d);
        p=NULL;
        cout<<"Element deleted successfully\n"<<endl;
    }
    else if (p->left == NULL)
    {
        d=p;
        free(d);
        p=p->right;
        cout<<"Element deleted successfully\n"<<endl;
    }
    else if (p->right == NULL)
    {
        d=p;
        p=p->left;
        free(d);
        cout<<"Element deleted successfully\n"<<endl;
    }
    else
    {
        p->gajiBID = deletemin(p->right);
    }
}

int bstree::deletemin(nodeptr &p)
{
    int c;
    cout<<"inside deltemin\n"<<endl;
    if (p->left == NULL)
    {
        c=p->gajiBID;
        p=p->right;
        return c;
    }
    else
    {
        c=deletemin(p->left);
        return c;
    }
}
void bstree::preorder(nodeptr p)
{
    if (p!=NULL)
    {
        cout << "----------------------------------------------" << endl;
        cout<<"NIP   : "<<p->NIP;
        cout<<endl;
        cout<<"NIK   : "<<p->nikBidan;
        cout<<endl;
        cout<<"Nama  : "<<p->namaBidan;
        cout<<endl;
        cout<<"TTL   : "<<p->tmptLahirBidan<<","
          <<p->tglLahirBidan;
        cout<<endl;
        cout<<"Alamat  :   Jln "<<p->jlnBidan;
        cout<<endl;
        cout<<"            RT/RW     : "<<p->rtBidan<<"/"
          <<p->rwBidan;
        cout<<endl;
        cout<<"            Kel/Desa  : "<<p->desaBidan;
        cout<<endl;
        cout<<"            Kec       : "<<p->kecBidan;
        cout<<endl;
        cout<<"            Kab/Kota  : "<<p->kabBidan;
        cout<<endl;
        cout<<"            Provinsi  : "<<p->provBidan;
        cout<<endl;
        cout<<"No HP : "<<p->noHp;
        cout<<endl;
        cout<<"Gaji Bidan : "<<p->gajiBID;
        cout<<endl;
        cout << "----------------------------------------------" << endl;
        cout<<"\n\n";
        preorder(p->left);
        preorder(p->right);
    }
}

// Inorder Printing
void bstree::inorder(nodeptr p)
{
    if (p!=NULL)
    {
        inorder(p->left);
        cout << "----------------------------------------------" << endl;
        cout<<"NIP   : "<<p->NIP;
        cout<<endl;
        cout<<"NIK   : "<<p->nikBidan;
        cout<<endl;
        cout<<"Nama  : "<<p->namaBidan;
        cout<<endl;
        cout<<"TTL   : "<<p->tmptLahirBidan<<","
          <<p->tglLahirBidan;
        cout<<endl;
        cout<<"Alamat  :   Jln "<<p->jlnBidan;
        cout<<endl;
        cout<<"            RT/RW     : "<<p->rtBidan<<"/"
          <<p->rwBidan;
        cout<<endl;
        cout<<"            Kel/Desa  : "<<p->desaBidan;
        cout<<endl;
        cout<<"            Kec       : "<<p->kecBidan;
        cout<<endl;
        cout<<"            Kab/Kota  : "<<p->kabBidan;
        cout<<endl;
        cout<<"            Provinsi  : "<<p->provBidan;
        cout<<endl;
        cout<<"No HP : "<<p->noHp;
        cout<<endl;
        cout<<"Gaji Bidan : "<<p->gajiBID;
        cout<<endl;
        cout << "----------------------------------------------" << endl;
        cout<<"\n\n";
        inorder(p->right);
    }
}

// PostOrder Printing
void bstree::postorder(nodeptr p)
{
    if (p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << "----------------------------------------------" << endl;
        cout<<"NIP   : "<<p->NIP;
        cout<<endl;
        cout<<"NIK   : "<<p->nikBidan;
        cout<<endl;
        cout<<"Nama  : "<<p->namaBidan;
        cout<<endl;
        cout<<"TTL   : "<<p->tmptLahirBidan<<","
          <<p->tglLahirBidan;
        cout<<endl;
        cout<<"Alamat  :   Jln "<<p->jlnBidan;
        cout<<endl;
        cout<<"            RT/RW     : "<<p->rtBidan<<"/"
          <<p->rwBidan;
        cout<<endl;
        cout<<"            Kel/Desa  : "<<p->desaBidan;
        cout<<endl;
        cout<<"            Kec       : "<<p->kecBidan;
        cout<<endl;
        cout<<"            Kab/Kota  : "<<p->kabBidan;
        cout<<endl;
        cout<<"            Provinsi  : "<<p->provBidan;
        cout<<endl;
        cout<<"No HP : "<<p->noHp;
        cout<<endl;
        cout<<"Gaji Bidan : "<<p->gajiBID;
        cout<<endl;
        cout << "----------------------------------------------" << endl;
        cout<<"\n\n";
    }
}

int bstree::max(int value1, int value2)
{
    return ((value1 > value2) ? value1 : value2);
}
int bstree::bsheight(nodeptr p)
{
    int t;
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        t = p->height;
        return t;
    }
}

nodeptr bstree:: srl(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->left;
    p1->left = p2->right;
    p2->right = p1;
    p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
    p2->height = max(bsheight(p2->left),p1->height) + 1;
    return p2;
}
nodeptr bstree:: srr(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->right;
    p1->right = p2->left;
    p2->left = p1;
    p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
    p2->height = max(p1->height,bsheight(p2->right)) + 1;
    return p2;
}
nodeptr bstree:: drl(nodeptr &p1)
{
    p1->left=srr(p1->left);
    return srl(p1);
}
nodeptr bstree::drr(nodeptr &p1)
{
    p1->right = srl(p1->right);
    return srr(p1);
}

int bstree::nonodes(nodeptr p)
{
    int count=0;
    if (p!=NULL)
    {
        nonodes(p->left);
        nonodes(p->right);
        count++;
    }
    return count;
}

