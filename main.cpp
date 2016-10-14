#include <iostream>
#include <string>

class Neuron{
    public:
        Neuron(){
            input = 0;
            output = 0;
        }
        
        ~Neuron(){
        }
        
        void processing(){
            output = input;   
        }
        
        void set_zero(){
            input = 0;   
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
        
        ~Synapse(){
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
    
    c.set_zero();
    
    ac.processing();
    bc.processing();
    
   
    
    std::cout << "Result is " << c.output;

}
