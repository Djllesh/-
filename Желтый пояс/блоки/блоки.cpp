#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;
class Parallelepiped
{
public:
    void SetBlock(uint64_t w, uint64_t h, uint64_t l)
    {
        width = w; 
        height = h;
        lenght = l;
    }
    uint64_t CalculateMass(uint64_t d)
    {
        density = d;
        return mass = width * height * lenght * d;
    }
private:
    uint64_t width, height, lenght, density, mass;
};

int main() {
    
    uint64_t N, R, res = 0;
    cin >> N >> R;
    vector<Parallelepiped> block_vec(N);
    for (uint64_t i = 0; i < N; i++)
    {
        uint64_t w, h, d;
        cin >> w >> h >> d;
        block_vec[i].SetBlock(w, h, d);
        res += block_vec[i].CalculateMass(R);
    }
    cout << res;
  	return 0;
}
