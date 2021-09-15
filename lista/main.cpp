#include <iostream>
#include "lista.hpp"

int main (int argc, char *argv[]) {
    stl_br::Lista<int> lista;
    lista.insereInicio(1);
    lista.insereFim(3);
    lista.insereFim(4);
    lista.insereFim(5);
    lista.insereOrdenado(0);
    lista.insereOrdenado(6);
    lista.insereOrdenado(2);

    std::cout << "[ ";
    for(auto it = lista.inicio(); it; it = it->proximo) {
        std::cout << it->dado << ' ';
    }
    std::cout << "]\n";

    lista.retiraFim();
    lista.retiraInicio();
    lista.retira(3);
    std::cout << "[ ";
    for(auto it = lista.inicio(); it; it = it->proximo) {
        std::cout << it->dado << ' ';
    }
    std::cout << "]\n";

    std::cout << "Tamanho dessa lista = " << lista.tam() << '\n';

    std::cout << "Encontrei 1 " << (lista.acha(1)? "Sim\n" : "Não\n");
    std::cout << "Encontrei -1 " << (lista.acha(-1)? "Sim\n" : "Não\n");

    std::cout << "Elemento na posição 2 = " << lista.naPos(2)->dado << '\n';

    std::cout << "Testando copias\n";
    auto lista2 = lista;
    std::cout << "Possuem os mesmos elementos? " << (lista2 == lista ? "Sim" : "Não") << '\n';
    std::cout << "Possuem os mesmos ponteiros? " << (lista2.inicio() == lista.inicio() ? "Sim" : "Não") << '\n';

    return 0;
}
