#include <iostream>
#include <string>

class Neuron{
    public:
        Neuron(){
            input = 0;
            output = 0;
        }

        void processing(){
            output = input;   
        }
      
        long double input, output;
    private:
};

class Synapse{
    public:
        Synapse(Neuron *_a, Neuron *_b, long double def_w = 1){
            a = _a;
            b = _b;
            weight = def_w;
        }
 
        void processing(){
            b->input += (a->output * weight);
            b->processing();
        }
        
        long double weight;
    private:
        Neuron *a, *b;
        
};

int main(){
    Neuron a, b, c;
    
    Synapse ac(&a,&c,0.3);
    Synapse bc(&b,&c,0.4);
    
    a.output = 1;
    b.output = 1;
    
    c.input = 0;
    
    ac.processing();
    bc.processing();
    
   
    
    std::cout << "Result is " << c.output;

}
