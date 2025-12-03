/* This file is an example on variables, pointers, addressof.
 Walk through the code and try to understand the concepts.
 */

#include <iostream>


int main(int argc, char* argv[])
{
    std::cout << "1) Deklarera en ny variabel av typen int \'a\' på stacken (int a;).\n";
    int a = 0;
    // Värdet går inte att lita på, men något skräpvärde finns troligen sedan tidigare på minnesplatsen. När en oinitierad variabel används, så genereras normalt ett varningsmeddelande vid kompilering.
    
    std::cout << "Gammalt innehåll(värde) på minnesadressen för \'a\' är: " << a << "\n"; // Ger varningsmeddelande!
    
    std::cout << "2) Tilldela variabeln \'a\' ett nytt heltalsvärde (a = 5)\n";
    a = 5;
    std::cout << "Nytt innehåll(värde) på minnesadressen för \'a\' är: " << a << "\n";
    
    std::cout << "3) Deklarera OCH initiera en ny variabel \'b\' på stacken (int b = 73)\n";
    int b = 73;
    std::cout << "Innehållet(värdet) på minnesadressen för \'b\' är: " << b << "\n";
    std::cout << "Variabeln \'b\' finns på adressen(&b): "<< &b << "\n";
    
    std::cout << "4) Deklarera ny variabel \'c\' av typen pekare till en 'int' OCH initiera med adressen till 'b' på stacken (int *c = &b).\n";
    int *c = &b;
    std::cout << "Innehållet(värdet) i minnesadressen som pekas ut av \'c\'(*c) är: " << *c << "\n";
    
    std::cout << "Innehållet(värdet) i minnesadressen för \'c\' är: " << c << "(samma som minnesadressen för \'b\'(&b)): " << &b <<"\n";
    
    std::cout << "\'c\' är egentligen på minnesadress(&c): " << &c << std::endl;
    
    std::cout << "5) Deklarera ny variabel \'d\' av typen pekare till en pekare till en 'int'(int** d).\n";
    int** d;
    std::cout << "Tilldela 'd' minnesadressen till minnesadressen för 'c'(d = &c).\n";
    d = &c;
    
    std::cout << "\'**d\' pekar nu till det som \'c\' pekar till: " << **d << std::endl;
    
    std::cout << "\'*d\' pekar till: " << *d << std::endl;
    
    std::cout << "\'d\' innehåller egentligen värdet: " << d << std::endl;
    
    std::cout << "\'d\'(" << d << ") är samma värde som \'c\':s minnesadress(&c): " << &c << std::endl;
    
    std::cout << "\'d\' är egentligen på minnesadress(&d): " << &d << std::endl;
    
    std::cout << "\'**&d\' visar vad som finns i minnesadressen: " << **&d << std::endl;
    
    
    std::cout << "Retur för att avsluta" << "\n";
    
    std::cin.get();
    
    return 0;
}
