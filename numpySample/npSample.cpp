#include<iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> makeArr(double A,double B,double C){
    py::module_ np = py::module_::import("numpy");
    py::array_t<double> Arr = np.attr("zeros")(py::make_tuple(3, 3));
    Arr.mutable_at(0,0) = A;
    Arr.mutable_at(1,1) = B;
    Arr.mutable_at(2,2) = C;
    return Arr;
}
py::array_t<double> makeZeros(){
    py::module_ np = py::module_::import("numpy");
    return np.attr("zeros")(3);
}
py::array_t<double> makeEye(){
    py::module_ np = py::module_::import("numpy");
    return np.attr("eye")(3);
}

PYBIND11_MODULE(npSample,m){
    m.doc()="pybind11 sample numpy module";
    m.def("makeArr", &makeArr, "make Arr");
    m.def("makeZeros", &makeZeros, "make Zeros");
    m.def("makeEye", &makeEye, "make Eye");
}