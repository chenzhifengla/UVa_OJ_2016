//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>

int main(){
    char c;
    bool q = true;
    while ((c = getchar()) != EOF){
        if (c == '"'){
            printf("%s", q ? "``" : "''");
            q = !q;
        }
        else{
            printf("%c", c);
        }
    }
    return 0;
}