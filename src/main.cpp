#include <boost/program_options.hpp>
#include <iostream>


int main(int argc, char* argv[]) {
    namespace po = boost::program_options;

    po::options_description desc("Allowed Options");

    double dt;
    double T;
    int Nx;
    int Ny;
    double a;
    double b;
    double mu1;
    double mu2;
    double eps;

    desc.add_options()
    ("help", "Produces help message.")
    ("dt", po::value<double>(&dt)->default_value(1), "Time-step to use")
    ("T", po::value<double>(&T)->default_value(1), "Total integration time.")
    ("Nx", po::value<int>(&Nx)->default_value(101), "Number of grid points in x.")
    ("Ny", po::value<int>(&Ny)->default_value(101), "Number of grid points in y.")
    ("a", po::value<double>(&a)->default_value(0.75), "Value of parameter a.")
    ("b", po::value<double>(&b)->default_value(0.06), "Value of parameter b.")
    ("mu1", po::value<double>(&mu1)->default_value(5.0), "Value of parameter mu1.")
    ("mu2", po::value<double>(&mu2)->default_value(0.0), "Value of parameter mu2.")
    ("eps", po::value<double>(&a)->default_value(50.0), "Value of parameter epsilon.");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")){
        std::cout << desc << '\n';
        return 0;
    }

    return 0;
}