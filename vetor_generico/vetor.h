#include <iostream>

template<typename T>

class Vetor {
private:
    T *dados; // Vetor de dados para qualquer tipo
    uint32_t tam; // ultimo elemento valido
    uint32_t max_tam; // quantidade maxima possivel
public:
    Vetor() {
        std::cout << "Iniciando o Objeto vetor" << std::endl;
        this->dados = nullptr;
        this->tam = 0;
        this->max_tam = 0;
    }

    ~Vetor() {
        libera();
        std::cout << "Deletando o Objeto vetor" << std::endl;
    }

    void libera() {
        if (this->dados != nullptr) {
            delete[] dados;
            tam = 0;
            max_tam = 0;
            dados = nullptr;
        }
    }

    void aloca(long int quantidade) {
        if (quantidade > 0 && quantidade <= UINT32_MAX) {
            this->max_tam = (uint32_t)quantidade;;
            dados = new(std::nothrow) T[max_tam];
            if (dados == nullptr) {
                std::cerr << "Falha ao alocar o vetor" << std::endl;
            }
        }
    }

    void setDado(T dado, uint32_t indice) {
        this->dados[indice] = dado;
    }

    uint32_t getUsedTam() {
        return tam;
    }

    uint32_t getMaxTam() {
        return tam;
    }

    friend std::ostream& operator<< (std::ostream& out, const Vetor <T>&v) {
        out << "[ ";
        for (uint32_t i = 0; i < v.tam; i++) {
            out << v.dados[i] << ' ';
        }
        out << v.dados[v.tam] << " ]" << std::endl;
        return out;
    }
    void print() {
    }

    T &operator [](uint32_t index) {
        try {
            if (index > tam && index < max_tam) {
                this->tam = index;
            }
            
            return dados[index];
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    T maior() {
        T maior = dados[0];
        for(int i = 1; i <= tam; i++) {
            if (dados[i] > maior) {
                maior = dados[i];
            }
        }
        return maior;
    }

    //============ Métodos de ordenação ============//
    void selectionSort() {
        int i, j, menor;
        for(i = 0; i <= tam; i++) {
            menor = i;
            for(j = i + 1; j <= tam; j++) {
                if(dados[j] < dados[menor]) {
                    menor = j;
                }
            }
            std::swap(dados[i], dados[menor]);
        }
    }

    Vetor countingSort(uint8_t range = UINT8_MAX, bool copy = true) {
        Vetor output;
        if (!std::is_same<T, int>::value) {
            std::cerr << "Essa ordenação só funciona para inteiros"
                        << std::endl;
            return output;
        }
        if (range == UINT8_MAX) {
            range = maior();
        }
        int i;
        int count[range] = {};
        output.aloca(this->tam + 1);

        for(i = 0; i <= this->tam; i++) {
            count[dados[i]]++;
        }

        for(i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        for(i = 0; i <= tam; i++) {
            int save_pos = dados[i]; 
            output[count[save_pos] - 1] = save_pos;
            count[save_pos]--;
        }

        if (copy) {
            for(i = 0; i <= tam; i++) {
                dados[i] = output.dados[i];
            }
        }
        return output;
    }
};