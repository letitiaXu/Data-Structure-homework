/* sicily 1150           BFS                with STL queue */
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N; //max times
//use struct to store moban and string
struct m{
    int moban[2][4];
    string s;
}start, end;

//if moban become the target we want
bool isTarget(m current, m end) {
   int count = 0;
   for (int i = 0; i < 2; i++) 
      for (int j = 0; j < 4; j++) 
         if (current.moban[i][j] == end.moban[i][j]) 
            count++;

   return (count == 8);
}
//the A B C change
void change(int id, m& next, m current) {
    switch(id){
        case 1:
            next.s = current.s + "A";
            for (int i = 0; i < 4; i++) {
                next.moban[1][i] = current.moban[0][i];
                next.moban[0][i] = current.moban[1][i];
            }
            break;

        case 2:
            next.s = current.s + "B";
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    next.moban[i][(j + 1) % 4] = current.moban[i][j];
                }
            }
            break;

        case 3:
            next.s = current.s + "C";
            for (int i = 0; i < 2; i++) 
                for (int j = 0; j < 4; j++) 
                    next.moban[i][j] = current.moban[i][j];

            next.moban[0][1] = current.moban[1][1];
            next.moban[0][2] = current.moban[0][1];
            next.moban[1][2] = current.moban[0][2];
            next.moban[1][1] = current.moban[1][2];
            break;

    }
}


void bfs(){
	for (int l = 0; l < 4; l++) {
        start.moban[0][l] = l + 1 ;
        start.moban[1][l] = 8 - l ;
    }
	start.s = "";
	//STL queue
    queue<m> q;
    if (isTarget(start, end)) {
        cout << 0 <<endl;
        return ;
    }
    q.push(start);
    while (1) {
        m current = q.front();
        q.pop();
        if (current.s.size() > N) {
            cout << -1 << endl;
            return ;
        }
        for (int i = 1; i <= 3; i++) {
            m next;
            change(i, next, current);
            if (isTarget(next, end)) {
                cout << next.s.size() << " " << next.s << endl;
                return ;
            }
            q.push(next) ;
        }
    }
}

int main() {
    
    while ( cin >> N && N != -1 && N <= 10) {

        //end moban
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> end.moban[i][j];
            }
        }
        bfs();
    }
    return 0;
}
