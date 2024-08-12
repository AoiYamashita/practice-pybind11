#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

class SampleClass{
public:
    SampleClass(void){}
    int add(int i,int j){
        return i+j;
    }

    int sub(int i,int j){
        return i-j;
    }

    int fib(int num){
        if(num <= 1)return 1;
        return fib(num-1)+fib(num-2);
    }

    float Leibniz(int Num){
        float n = 0;
        for(int i = 0;i < Num;i++){
            if(i % 2 == 0)n += 1.0/(2*i+1);
            else n -= 1.0/(2*i+1);
        }
        return n;
    }

    py::array_t<double> dot(py::array_t<double> A){
        py::module_ np = py::module_::import("numpy");
        return np.attr("matmul")(A,np.attr("transpose")(A));
    }
};

PYBIND11_MODULE(sample,m) {
    //py::module m("sample","pybind11 sample plugin");
    py::class_<SampleClass>(m,"SampleClass")
        .def(py::init<>())
        .def("add", &SampleClass::add)
        .def("sub", &SampleClass::sub)
        .def("fib", &SampleClass::fib)
        .def("Leibniz", &SampleClass::Leibniz)
        .def("dot", &SampleClass::dot)
        .def("__repr__",
            [](const SampleClass &a) {
                return "<pybind11 sample plugin>";
            }
        );
    
}