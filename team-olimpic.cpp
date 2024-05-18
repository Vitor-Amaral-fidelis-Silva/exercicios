#include <bits/stdc++.h>
using namespace std;

int achar_posicao(vector<pair<int, int>> turma, int valor);

int main(){
    int n; cin >> n;
    vector<pair<int, int>> turma; //aluno ={aptidao, posicao}
    for(int i  = 0; i < n; i++){
        int aptidao; cin >> aptidao; 
        turma.push_back(make_pair(aptidao, i + 1));
    }
    vector<vector<int>> times;
    vector<int> time_formado;
    queue<int> aptidao; //equipe necessária para formar um time
    aptidao.push(1);
    aptidao.push(2);
    aptidao.push(3);
   while(true){ //enquanto eu conseguir completar um time continuo a formar
        int posicao = achar_posicao(turma, aptidao.front());
        if(posicao == -1) //se eu não encontrar um integrante eu paro
            break;
        int nota = turma[posicao].second;
        time_formado.push_back(nota);
        aptidao.pop();
        turma.erase(turma.begin() + posicao);
        if(aptidao.empty()){ //Se a equipe foi formada eu injeto os integrantes em times e reinicio a fila
            times.push_back(time_formado);
            time_formado.clear();
            aptidao.push(1);
            aptidao.push(2);
            aptidao.push(3);
        }
    }
    
    cout << times.size() << endl;
    for(auto time: times){
        for(auto aluno: time){
            cout << aluno << " ";
        }
        cout << endl;
    
    }
}

int achar_posicao(vector<pair<int, int>> turma, int valor){
    for(int i = 0; i < turma.size(); i++){
        if(turma[i].first == valor)
            return i;
    }
    return -1;
}