#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <cmath>

namespace py = pybind11;

class Sample{
    private:
    int a;
    public:
    Sample()
    {
    }
    py::array_t<double> dot(py::array_t<double> A){
        py::module_ np = py::module_::import("numpy");
        py::detail::str_attr_accessor matmul = np.attr("matmul");
        py::array_t<double> B = matmul(matmul(A,np.attr("transpose")(A)),A);
        this->a = 10;
        py::buffer_info buf_info = B.request();
        for(int i = 0;i < buf_info.shape[0];i++)
            for(int j = 0;j < buf_info.shape[1];j++)
                B.mutable_at(i,j) *= 3;
        return B;
    }
    py::array_t<double> dot(py::none A){
        py::module_ np = py::module_::import("numpy");
        return np.attr("eye")(3);
    }
    py::array_t<double> returnZeroZero(py::array_t<double> A){
        int s = A.request().shape[0];
        py::module_ np = py::module_::import("numpy");
        py::detail::str_attr_accessor zeros = np.attr("zeros");
        py::array_t<double> Sample = zeros(s);
        for(int i = 0;i < s;i++)Sample.mutable_at(i) = sin(A.mutable_at(i));
        return Sample;
    }
    void print(){
        py::print(a);
    }
};

PYBIND11_MODULE(npClassSample,m){
    py::class_<Sample>(m,"npClassSample")
        .def(py::init<>())
        .def("dot", (py::array_t<double> (Sample::*) (py::array_t<double>))&Sample::dot)
        .def("dot", (py::array_t<double> (Sample::*) (py::none))&Sample::dot)
        .def("print", &Sample::print)
        .def("returnZeroZero", &Sample::returnZeroZero)
        .def("__repr__",
            [](const Sample &a) {
                return "<pybind11 sample plugin>";
            }
        );
}