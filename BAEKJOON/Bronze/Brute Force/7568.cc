#include <iostream>
#include <vector>

class Man {
    public:
    int weight;
    int height;
    int num = 1;

    Man(int x, int y): height(x), weight(y) {}
};

int main() {
        int N;
        std::cin >> N;

        std::vector<Man> man_vec;
        std::vector<int> height_vec;
        std::vector<int> weight_vec;

        for(int i =0; i < N; i++) {
            int x, y;
            std::cin >> x >> y;
            Man man(x, y);
            man_vec.push_back(man);
            height_vec.push_back(x);
            weight_vec.push_back(y);    
        }

        std::vector<int> num_vec;


        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                if(man_vec[i].height > man_vec[j].height && man_vec[i].weight > man_vec[j].weight)
                    man_vec[j].num++;
                else if(man_vec[i].height < man_vec[j].height && man_vec[i].weight < man_vec[j].weight)
                    man_vec[i].num++;
            }
        }

        for(int i = 0; i < N; i++) 
            std::cout << man_vec[i].num <<" ";
}