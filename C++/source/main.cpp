#include<iostream>
#include<fstream>
#include<string.h>
#include <stdio.h>
#include<iterator> // for iterators
#include<vector> // for vectors
#include<cmath>
#include<future>
#include<thread>
#include<chrono>
// #include "../include/gnuplot-iostream.h"
#include "../include/plotting.hpp"
#include "../include/biffurcation.hpp"
#include "../include/penduli.hpp"
#include "../include/lyapunov.hpp"
#include "../include/lorenz.hpp"
#include "../include/printing.hpp"
#include "../include/discretelyap.hpp"

void runge(std::vector<double> integrationAux, double tau, double gamma,std::vector<long double> &lya);
void discrete(std::vector<double> integrationAux, double tau, int iteration, double gamma, double k,std::vector<long double> &lya);
void plt(std::vector<double> integrationAux, double tau, int iteration, double gamma, double k, int i);

// void allInOne(std::vector<double>(*function)(std::vector<double>, double),
//                                         std::vector<std::vector<double>> (*jacobian)(std::vector<double>&,double),
//                                         double paramRange[2], std::vector<double> initialCond, 
//                                         double paramStep, double integrationStep, int systemDimension)
// {

//     int paramIterations = (int)((fabs(paramRange[1]-paramRange[0])/paramStep));
//     int integrationIterations = (int)((double)100.0/integrationStep);
//     std::vector<std::vector<double>> biffurcation (4);
//     std::vector<std::vector<double>> auxCoord(integrationIterations);
//     auxCoord[0]= initialCond;

//     std::vector<double> param (paramIterations,0);
//     std::vector<double>::iterator paramValue;
//     std::vector<double> xCoord (integrationIterations-1,0);
//     std::vector<double> auxIntegration;

//     std::vector<std::vector<double>> w = identityMatrix(initialCond.size());  
//     std::vector<std::vector<double>> J = identityMatrix(initialCond.size());
//     std::vector<std::vector<long double>> lyapunovExponents (paramIterations ,std::vector<long double> (initialCond.size()+1,0));
    
//     for(int i = 0; i < paramIterations; i++)
//     {
//         param[i] = i*paramStep;
//         // std::cout<<param[i]<<" \n";
//     } 
    
//     int k = 0;
//     for(paramValue = param.begin(); paramValue<param.end(); paramValue++)
//     {
//         //integration for transient state
//         for(int i = 0; i < integrationIterations-1; i++)
//         {
//             auxCoord[i+1] = rungeKutta4thSquare(function, auxCoord[i], *paramValue, integrationStep,systemDimension);
//             J = jacobian(auxCoord[i],integrationStep);
//             w = matMult(J,w);
//             transpostSquare(w);
//             gramSchmidt(w);
        
//             for(uint l = 0; l < initialCond.size(); l++)
//             {
//                 lyapunovExponents[k][l+1] +=  log(normOf(w[l]));
//             }
        
//             gramSchmidtNormal(w);
//             transpostSquare(w);
//             xCoord[i] = auxCoord[i][2];
//         }
//         lyapunovExponents[k][0] =(double)(*paramValue);
//         for(uint j = 1; j < initialCond.size(); j++)
//         {
//             lyapunovExponents[k][j] = lyapunovExponents[k][j]/((long double)(100.0));
//         }
//         k++;
//         auxCoord[0] = initialCond;
//         // auxCoord[0] = auxCoord[integrationIterations-1];
        

//         // for(int i = 1; i < integrationIterations-2; i++)
//         // {
//         //     if((xCoord[i-1]<xCoord[i]) & (xCoord[i]>xCoord[i+1]))
//         //     {
//         //         biffurcation[1].push_back(xCoord[i]);
//         //         biffurcation[0].push_back((double)(*paramValue));
//         //         if(xCoord[i+1]<xCoord[i+2])
//         //         {
//         //             biffurcation[2].push_back(xCoord[i+1]);
//         //             biffurcation[3].push_back((double)(*(paramValue + 1)));
//         //             i++;
//         //         }
//         //     }
//         //     else if((xCoord[i]<xCoord[i-1]) & (xCoord[i]< xCoord[i+1]))
//         //     {
//         //         biffurcation[3].push_back(xCoord[i]);
//         //         biffurcation[2].push_back((double)(*paramValue));
//         //         if(xCoord[i+1]>xCoord[i+2])
//         //         {
//         //             biffurcation[0].push_back(xCoord[i+1]);
//         //             biffurcation[1].push_back((double)(*(paramValue + 1)));
//         //             i++;
//         //         }
//         //     }
//         // }
//         xCoord.clear();
//     }
  

//     printLyapunovsToFile(lyapunovExponents, "lyapunovExpHistLorenz1");
//     printBiffucationToFile(biffurcation, "biffurcationAndLyapunovExponents1");
//     plotBiffucationAndLyapunovExp("biffurcationAndLyapunovExponents1", "lyapunovExpHistLorenz1",
//                                  "Lorenz System", "{/Symbol r}", "");


// }
int main()
{
    std::vector<double> integrationAux1 = {6.0,0.0,1.0,1.0};
    std::vector<double> integrationAux2 = {6.0,0.0,1.0,1.0};
    // double time[2] = {0,10.0};
    // std::vector<std::vector<double>> rk45 (100000, std::vector<double>(3,0));
    // double time;
    std::vector<double> hs; 
    // std::vector<std::vector<double>>  biff = biffurcation(lorenz, time,integrationAux,0.1,0.1,0,3);
    // printBiffucationToFile(biff, "testplot");
    // plotBiffucation("testplot","lorenz test","rho", "");
    // completeRungeKutta45(lorenz,integrationAux,100000, rk45, 28.0,0.001,3,1e-5, time, hs);
    // printMatrixToFile(rk45,"testeRK45.dat");
    // plot3D("testeRK45","testeRK45", "lorenz Atrractor", "");

  //  printMatrix(rk45);
    // double stepNew; 
    // rungeKutta45(lorenz,integrationAux,rk45,28.0, 0.0150955,3, 1e-2 ,stepNew);
    // std::vector<double> rk4s =rungeKutta4thSquare(lorenz,integrationAux,28.0, 1e-2,3);
    // std::cout<<"rk4 novo: "<< rk45[0]<<", "<<rk45[1]<<", "<<rk45[2]<<"\n";
    // std::cout<<"error : "<< rk5[0]<<", "<<rk5[1]<<", "<<rk5[2]<<"\n";
    // std::cout<<"rk4 velho: "<< rk4s[0]<<", "<<rk4s[1]<<", "<<rk4s[2]<<"\n";
    // std::cout<<"novo step: "<<stepNew;
    // double time[2] = {0.0,1.0};

    // int iterations = (int)(fabs(time[1]-time[0])/0.1);
    //std::vector<std::vector<double>> A;// (iterations, std::vector<double> (integrationAux.size()+1));
    
    /*laypunovVaringParameter(quantumPendulum,classicalPendulumJacobian,time,integrationAux,1e-8,0.01,4,A);
    printMatrixToFile(A,"arquivoTesteLyapunovVsRho.dat");
    */
    //A = discreteClassLyap(integrationAux, 1, 0.1, 500,1);
    double tau = 1e-4;
    int iteration = 5e5;
    double k = 1;
    double gamma = 0;
    std::vector<long double> lyap[5];
    std::vector<long double> lyapunovexponent (5,0);

    std::vector<double> max (integrationAux1.size(), 0);
    std::vector<double> min (integrationAux1.size(), 0);
    std::ofstream lyapexp("outputs/txt/Gamma-Lyapunov-exponents3.dat");
    std::ofstream lyapnum("outputs/txt/Gamma-Lyapunov-numbers3.dat");
    std::ofstream lyapsum("outputs/txt/Gamma-Lyapunov-sum3.dat");

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 51;i++)
    {
      std::thread task1(plt, integrationAux1, tau, iteration, gamma, k, i);
      std::thread task2(plt, integrationAux1, tau, iteration, gamma, k, i+50);
      std::thread task3(plt, integrationAux1, tau, iteration, gamma, k, i+100);
      task1.join();
      task2.join();
      task3.join();
      gamma += 0.01;
    }
    for (int i = 0; i < 151; i++)
    {
      std::cout << gamma << std::endl;
      lyapexp << gamma;
      lyapnum << gamma;
      lyapsum << gamma;
      //std::thread task1(runge, integrationAux1, tau, gamma, std::ref(lyap[0]));
      //std::thread task2(runge, integrationAux1, tau, gamma, std::ref(lyap[1]));
      //std::thread task3(runge, integrationAux1, tau, gamma, std::ref(lyap[2]));
      //std::thread task4(runge, integrationAux1, tau, gamma, std::ref(lyap[3]));
      //std::thread task5(runge, integrationAux1, tau, gamma, std::ref(lyap[4]));
      for (int j = 0; j < 20; j++)
      {
        std::thread task1(discrete, integrationAux2, tau, iteration, gamma, k, std::ref(lyap[0]));
        std::thread task2(discrete, integrationAux2, tau, iteration, gamma, k, std::ref(lyap[1]));
        std::thread task3(discrete, integrationAux2, tau, iteration, gamma, k, std::ref(lyap[2]));
        std::thread task4(discrete, integrationAux2, tau, iteration, gamma, k, std::ref(lyap[3]));
        std::thread task5(discrete, integrationAux2, tau, iteration, gamma, k, std::ref(lyap[4]));
        //std::thread task1(plt, integrationAux2, tau, iteration, gamma, k, i);
        //std::thread task2(plt, integrationAux2, tau, iteration, gamma+2, k, i+20);
        //std::thread task3(plt, integrationAux2, tau, iteration, gamma+4, k, i+40);
        task1.join();
        task2.join();
        task3.join();
        task4.join();
        task5.join();

        for (int k = 0; k < 5; k++)
        {
          lyapunovexponent[0] += lyap[k][0];
          lyapunovexponent[1] += lyap[k][1];
          lyapunovexponent[2] += lyap[k][2];
          lyapunovexponent[3] += lyap[k][3];
        }
        for (uint k = 0; k < integrationAux1.size(); k++)
        {
          lyapunovexponent[k] /= 1000;
        }
      }
      for (uint k = 0; k < integrationAux1.size(); k++)
      {
        lyapexp << "   " << exp(lyapunovexponent[k]);
        lyapnum << "   " << lyapunovexponent[k];
      }
      lyapexp << std::endl;
      lyapnum << std::endl;
      lyapsum << "   " << lyapunovexponent[0] + lyapunovexponent[1] + lyapunovexponent[2] + lyapunovexponent[3] << std::endl;
      lyapunovexponent[0] = 0;
      lyapunovexponent[1] = 0;
      lyapunovexponent[2] = 0;
      lyapunovexponent[3] = 0;

      /*std::cout << "For gamma = " << gamma << std::endl;
      lya[0] = lyapunovSpectrum(classicalPendulum, classicalPendulumJacobian, integrationAux1, 1e-6, 100, tau, 1e-4);
      std::cout << std::endl;
      */
      
      gamma += 0.01;
  }

      // std::cout<<"their sum : "<< lya[0]+lya[1]+lya[2]+lya[3];

      // std::vector<double> qpendulum = quantumPendulum(integrationAux,0.1);
      // std::cout<<qpendulum[0]<<", "<<qpendulum[1]<<", "<<qpendulum[2]<<", "<<qpendulum[3]<<"\n";
      // std::vector<std::vector<double>> biff = biffurcation(lorenz, time, integrationAux, 0.1,0.001,2,3);

      // printBiffucationToFile(biff,"biffucationLorenzTesteRK45");
      // plotBiffucation("biffucationLorenzTesteRK45","Lorenz System", " {/Symbol r}", " ");
      // plot2D("./outputs/images/biffucationLorenz","./outputs/txt/biffucationLorenzmax.dat", "max points"," plot ./outputs/txt/biffucationLorenzmin.dat w dots title \'min points\'  set title \'Biffurcation Diagram for the Lorenz system\'" );
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << std::endl << "Duration" << duration.count() << std::endl;
    return 0;
}

void runge(std::vector<double> integrationAux, double tau, double gamma,std::vector<long double>&lya)
{
  lya = lyapunovSpectrum(quantumPendulum, classicalPendulumJacobian, integrationAux, 1e-6, 100, tau, gamma);
  std::cout << std::endl;
  std::cout << "For gamma = " << gamma << std::endl;
  std::cout << "Runge lyapunov numbers: " << lya[0] << ", " << lya[1] << ", " << lya[2] << "," << lya[3] << "\n";
  std::cout << "Runge lyapunov exponents: " << exp(lya[0]) << ", " << exp(lya[1]) << ", " << exp(lya[2]) << ", " << exp(lya[3]) << "\n";
  std::cout << "Runge lyapunov sum : " << lya[0] + lya[1] + lya[2] + lya[3] << std:: endl;
  //std::cout << "algo" << std::endl;
}
void discrete(std::vector<double> integrationAux, double tau, int iteration, double gamma, double k, std::vector<long double> &lya)
{
  std::vector<std::vector<double>> A;
  A = discreteSys(integrationAux, gamma, tau, iteration, k);
  lya = discreteLyap(quantumPendulum, classicalPendulumJacobian, A, gamma, tau);

  //printMatrixToFile(A, "Discrete/teste.dat");
  //plot2D("Discrete/teste", "Discrete/teste", "teste", "teste");
  //std::cout << std::endl;
  //std::cout << "Discrete lyapunov numbers: " << lya[0] << ", " << lya[1] << ", " << lya[2] << "," << lya[3] << "\n";
  //std::cout << "Discrete lyapunov exponents: " << exp(lya[0]) << ", " << exp(lya[1]) << ", " << exp(lya[2]) << ", " << exp(lya[3]) << "\n";
  //std::cout << "Discrete lyapunov sum : " << lya[0] + lya[1] + lya[2] + lya[3] << std::endl;
  //std::cout << "anda mal" << std::endl;
}
void plt(std::vector<double> integrationAux, double tau, int iteration, double gamma, double k,int i)
{
  std::vector<std::vector<double>> A;
  std::string a = std::to_string(i);
  A = discreteSys(integrationAux, gamma, tau, iteration, k);
  printMatrixToFile(A, "Discrete/teste"+std::to_string(i)+".dat");
  //plot2D("Discrete/teste", "Discrete/teste", "teste", "teste");

}