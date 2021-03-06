// Class: ReadMLPDYQ6Type6
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================
#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-
Method         : MLP::MLP
TMVA Release   : 4.2.0         [262656]
ROOT Release   : 6.02/05       [393733]
Creator        : aackert
Date           : Wed Feb  1 06:58:26 2017
Host           : Linux cmsbuild12.cern.ch 2.6.32-573.7.1.el6.x86_64 #1 SMP Wed Sep 23 10:12:03 CEST 2015 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /afs/cern.ch/work/a/aackert/private/CMSSW_7_4_15/src/MVA/exercises/03_TMVA
Training events: 20000
Analysis type  : [Classification]
#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-
# Set by User:
HiddenLayers: "10TrainingMethod=BFGS" [Specification of hidden layer architecture]
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VarTransform: "N" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "False" [Print method-specific help message]
# Default:
NCycles: "500" [Number of training cycles]
NeuronType: "sigmoid" [Neuron activation function type]
RandomSeed: "1" [Random seed for initial synapse weights (0 means unique seed for each run; default value '1')]
EstimatorType: "MSE" [MSE (Mean Square Estimator) for Gaussian Likelihood or CE(Cross-Entropy) for Bernoulli Likelihood]
NeuronInputType: "sum" [Neuron input function type]
VerbosityLevel: "Default" [Verbosity level]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
TrainingMethod: "BP" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
LearningRate: "2.000000e-02" [ANN learning rate parameter]
DecayRate: "1.000000e-02" [Decay rate for learning parameter]
TestRate: "10" [Test for overtraining performed at each #th epochs]
EpochMonitoring: "False" [Provide epoch-wise monitoring plots according to TestRate (caution: causes big ROOT output file!)]
Sampling: "1.000000e+00" [Only 'Sampling' (randomly selected) events are trained each epoch]
SamplingEpoch: "1.000000e+00" [Sampling is used for the first 'SamplingEpoch' epochs, afterwards, all events are taken for training]
SamplingImportance: "1.000000e+00" [ The sampling weights of events in epochs which successful (worse estimator than before) are multiplied with SamplingImportance, else they are divided.]
SamplingTraining: "True" [The training sample is sampled]
SamplingTesting: "False" [The testing sample is sampled]
ResetStep: "50" [How often BFGS should reset history]
Tau: "3.000000e+00" [LineSearch "size step"]
BPMode: "sequential" [Back-propagation learning mode: sequential or batch]
BatchSize: "-1" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
ConvergenceImprove: "1.000000e-30" [Minimum improvement which counts as improvement (<0 means automatic convergence check is turned off)]
ConvergenceTests: "-1" [Number of steps (without improvement) required for convergence (<0 means automatic convergence check is turned off)]
UseRegulator: "False" [Use regulator to avoid over-training]
UpdateLimit: "10000" [Maximum times of regulator update]
CalculateErrors: "False" [Calculates inverse Hessian matrix at the end of the training to be able to calculate the uncertainties of an MVA value]
WeightRange: "1.000000e+00" [Take the events for the estimator calculations from small deviations from the desired value to large deviations only over the weight range]
##
#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-
NVar 3
P                             P                             P                             P                                                               'F'    [60.0715484619,1811.90710449]
Ih                            Ih                            Ih                            Ih                                                              'F'    [1.87020111084,29.1327552795]
eta                           eta                           eta                           eta                                                             'F'    [-2.09927392006,2.09983992577]
NSpec 0
============================================================================ */

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

public:

  // constructor
  IClassifierReader() : fStatusIsClean( true ) {}
  virtual ~IClassifierReader() {}

  // return classifier response
  virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

  // returns classifier status
  bool IsStatusClean() const { return fStatusIsClean; }

protected:

  bool fStatusIsClean;
};

#endif

class ReadMLPDYQ6Type6 : public IClassifierReader {

public:

  // constructor
  ReadMLPDYQ6Type6( std::vector<std::string>& theInputVars ) 
    : IClassifierReader(),
      fClassName( "ReadMLPDYQ6Type6" ),
      fNvars( 3 ),
      fIsNormalised( false )
  {      
    // the training input variables
    const char* inputVars[] = { "P", "Ih", "eta" };

    // sanity checks
    if (theInputVars.size() <= 0) {
      std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
      fStatusIsClean = false;
    }

    if (theInputVars.size() != fNvars) {
      std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
		<< theInputVars.size() << " != " << fNvars << std::endl;
      fStatusIsClean = false;
    }

    // validate input variables
    for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
      if (theInputVars[ivar] != inputVars[ivar]) {
	std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
		  << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
	fStatusIsClean = false;
      }
    }

    // initialize min and max vectors (for normalisation)
    fVmin[0] = -1;
    fVmax[0] = 1;
    fVmin[1] = -1;
    fVmax[1] = 1;
    fVmin[2] = -1;
    fVmax[2] = 1;

    // initialize input variable types
    fType[0] = 'F';
    fType[1] = 'F';
    fType[2] = 'F';

    // initialize constants
    Initialize();

    // initialize transformation
    InitTransform();
  }

  // destructor
  virtual ~ReadMLPDYQ6Type6() {
    Clear(); // method-specific
  }

  // the classifier response
  // "inputValues" is a vector of input values in the same order as the 
  // variables given to the constructor
  double GetMvaValue( const std::vector<double>& inputValues ) const;

private:

  // method-specific destructor
  void Clear();

  // input variable transformation

  double fMin_1[3][3];
  double fMax_1[3][3];
  void InitTransform_1();
  void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
  void InitTransform();
  void Transform( std::vector<double> & iv, int sigOrBgd ) const;

  // common member variables
  const char* fClassName;

  const size_t fNvars;
  size_t GetNvar()           const { return fNvars; }
  char   GetType( int ivar ) const { return fType[ivar]; }

  // normalisation of input variables
  const bool fIsNormalised;
  bool IsNormalised() const { return fIsNormalised; }
  double fVmin[3];
  double fVmax[3];
  double NormVariable( double x, double xmin, double xmax ) const {
    // normalise to output range: [-1, 1]
    return 2*(x - xmin)/(xmax - xmin) - 1.0;
  }

  // type of input variable: 'F' or 'I'
  char   fType[3];

  // initialize internal variables
  void Initialize();
  double GetMvaValue__( const std::vector<double>& inputValues ) const;

  // private members (method specific)

  double ActivationFnc(double x) const;
  double OutputActivationFnc(double x) const;

  int fLayers;
  int fLayerSize[3];
  double fWeightMatrix0to1[11][4];   // weight matrix from layer 0 to 1
  double fWeightMatrix1to2[1][11];   // weight matrix from layer 1 to 2

  double * fWeights[3];
};

inline void ReadMLPDYQ6Type6::Initialize()
{
  // build network structure
  fLayers = 3;
  fLayerSize[0] = 4; fWeights[0] = new double[4]; 
  fLayerSize[1] = 11; fWeights[1] = new double[11]; 
  fLayerSize[2] = 1; fWeights[2] = new double[1]; 
  // weight matrix from layer 0 to 1
  fWeightMatrix0to1[0][0] = -2.11749112526004;
  fWeightMatrix0to1[1][0] = 2.21415185143875;
  fWeightMatrix0to1[2][0] = 0.958370724412721;
  fWeightMatrix0to1[3][0] = 1.75921372242102;
  fWeightMatrix0to1[4][0] = -0.834708702161537;
  fWeightMatrix0to1[5][0] = -1.52715841782326;
  fWeightMatrix0to1[6][0] = -0.675691573869667;
  fWeightMatrix0to1[7][0] = 1.6272857507067;
  fWeightMatrix0to1[8][0] = -2.21692676783178;
  fWeightMatrix0to1[9][0] = 1.40929107348841;
  fWeightMatrix0to1[0][1] = -0.764558407980796;
  fWeightMatrix0to1[1][1] = 0.0279368380198311;
  fWeightMatrix0to1[2][1] = -1.09173031312152;
  fWeightMatrix0to1[3][1] = -0.232942271512715;
  fWeightMatrix0to1[4][1] = -0.993564970445971;
  fWeightMatrix0to1[5][1] = 2.18278822980972;
  fWeightMatrix0to1[6][1] = -0.474999257374044;
  fWeightMatrix0to1[7][1] = 2.33678482353263;
  fWeightMatrix0to1[8][1] = 0.179065631218548;
  fWeightMatrix0to1[9][1] = 4.72468080213756;
  fWeightMatrix0to1[0][2] = 0.0550936698326055;
  fWeightMatrix0to1[1][2] = -0.834153532120826;
  fWeightMatrix0to1[2][2] = -0.0180400527575813;
  fWeightMatrix0to1[3][2] = -0.0871388389062794;
  fWeightMatrix0to1[4][2] = -0.0552633126519251;
  fWeightMatrix0to1[5][2] = -0.757805841096147;
  fWeightMatrix0to1[6][2] = 1.49977712196265;
  fWeightMatrix0to1[7][2] = -1.91962585932047;
  fWeightMatrix0to1[8][2] = -1.36533221620334;
  fWeightMatrix0to1[9][2] = -0.27465710455877;
  fWeightMatrix0to1[0][3] = 0.556595702312564;
  fWeightMatrix0to1[1][3] = 1.42726942312056;
  fWeightMatrix0to1[2][3] = -1.20480310548439;
  fWeightMatrix0to1[3][3] = -0.347617773298671;
  fWeightMatrix0to1[4][3] = -0.419187434829349;
  fWeightMatrix0to1[5][3] = 0.81513153007336;
  fWeightMatrix0to1[6][3] = -1.75923492706301;
  fWeightMatrix0to1[7][3] = 1.82595871621572;
  fWeightMatrix0to1[8][3] = 0.195808646764344;
  fWeightMatrix0to1[9][3] = 3.82895181430136;
  // weight matrix from layer 1 to 2
  fWeightMatrix1to2[0][0] = 0.542991659323229;
  fWeightMatrix1to2[0][1] = 0.194119150415625;
  fWeightMatrix1to2[0][2] = 0.545922113009151;
  fWeightMatrix1to2[0][3] = -0.693183331668222;
  fWeightMatrix1to2[0][4] = -1.12805503908015;
  fWeightMatrix1to2[0][5] = -1.60248297933195;
  fWeightMatrix1to2[0][6] = -0.695052366319152;
  fWeightMatrix1to2[0][7] = -0.800203815878695;
  fWeightMatrix1to2[0][8] = 1.19278354796972;
  fWeightMatrix1to2[0][9] = 2.17084439745524;
  fWeightMatrix1to2[0][10] = 0.111782551311504;
}

inline double ReadMLPDYQ6Type6::GetMvaValue__( const std::vector<double>& inputValues ) const
{
  if (inputValues.size() != (unsigned int)fLayerSize[0]-1) {
    std::cout << "Input vector needs to be of size " << fLayerSize[0]-1 << std::endl;
    return 0;
  }

  for (int l=0; l<fLayers; l++)
    for (int i=0; i<fLayerSize[l]; i++) fWeights[l][i]=0;

  for (int l=0; l<fLayers-1; l++)
    fWeights[l][fLayerSize[l]-1]=1;

  for (int i=0; i<fLayerSize[0]-1; i++)
    fWeights[0][i]=inputValues[i];

  // layer 0 to 1
  for (int o=0; o<fLayerSize[1]-1; o++) {
    for (int i=0; i<fLayerSize[0]; i++) {
      double inputVal = fWeightMatrix0to1[o][i] * fWeights[0][i];
      fWeights[1][o] += inputVal;
    }
    fWeights[1][o] = ActivationFnc(fWeights[1][o]);
  }
  // layer 1 to 2
  for (int o=0; o<fLayerSize[2]; o++) {
    for (int i=0; i<fLayerSize[1]; i++) {
      double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
      fWeights[2][o] += inputVal;
    }
    fWeights[2][o] = OutputActivationFnc(fWeights[2][o]);
  }

  return fWeights[2][0];
}

double ReadMLPDYQ6Type6::ActivationFnc(double x) const {
  // sigmoid
  return 1.0/(1.0+exp(-x));
}
double ReadMLPDYQ6Type6::OutputActivationFnc(double x) const {
  // identity
  return x;
}
   
// Clean up
inline void ReadMLPDYQ6Type6::Clear() 
{
  // clean up the arrays
  for (int lIdx = 0; lIdx < 3; lIdx++) {
    delete[] fWeights[lIdx];
  }
}
inline double ReadMLPDYQ6Type6::GetMvaValue( const std::vector<double>& inputValues ) const
{
  // classifier response value
  double retval = 0;

  // classifier response, sanity check first
  if (!IsStatusClean()) {
    std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
	      << " because status is dirty" << std::endl;
    retval = 0;
  }
  else {
    if (IsNormalised()) {
      // normalise variables
      std::vector<double> iV;
      iV.reserve(inputValues.size());
      int ivar = 0;
      for (std::vector<double>::const_iterator varIt = inputValues.begin();
	   varIt != inputValues.end(); varIt++, ivar++) {
	iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
      }
      Transform( iV, -1 );
      retval = GetMvaValue__( iV );
    }
    else {
      std::vector<double> iV;
      int ivar = 0;
      for (std::vector<double>::const_iterator varIt = inputValues.begin();
	   varIt != inputValues.end(); varIt++, ivar++) {
	iV.push_back(*varIt);
      }
      Transform( iV, -1 );
      retval = GetMvaValue__( iV );
    }
  }

  return retval;
}

//_______________________________________________________________________
inline void ReadMLPDYQ6Type6::InitTransform_1()
{
  // Normalization transformation, initialisation
  fMin_1[0][0] = 61.5809249878;
  fMax_1[0][0] = 1811.90710449;
  fMin_1[1][0] = 60.0715484619;
  fMax_1[1][0] = 1240.82495117;
  fMin_1[2][0] = 60.0715484619;
  fMax_1[2][0] = 1811.90710449;
  fMin_1[0][1] = 1.87020111084;
  fMax_1[0][1] = 29.1327552795;
  fMin_1[1][1] = 2.26485323906;
  fMax_1[1][1] = 6.35099983215;
  fMin_1[2][1] = 1.87020111084;
  fMax_1[2][1] = 29.1327552795;
  fMin_1[0][2] = -2.09927392006;
  fMax_1[0][2] = 2.09983992577;
  fMin_1[1][2] = -2.09828233719;
  fMax_1[1][2] = 2.09932804108;
  fMin_1[2][2] = -2.09927392006;
  fMax_1[2][2] = 2.09983992577;
}

//_______________________________________________________________________
inline void ReadMLPDYQ6Type6::Transform_1( std::vector<double>& iv, int cls) const
{
  // Normalization transformation
  if (cls < 0 || cls > 2) {
    if (2 > 1 ) cls = 2;
    else cls = 2;
  }
  const int nVar = 3;

  // get indices of used variables

  // define the indices of the variables which are transformed by this transformation
  static std::vector<int> indicesGet;
  static std::vector<int> indicesPut;

  if ( indicesGet.empty() ) { 
    indicesGet.reserve(fNvars);
    indicesGet.push_back( 0);
    indicesGet.push_back( 1);
    indicesGet.push_back( 2);
  } 
  if ( indicesPut.empty() ) { 
    indicesPut.reserve(fNvars);
    indicesPut.push_back( 0);
    indicesPut.push_back( 1);
    indicesPut.push_back( 2);
  } 

  static std::vector<double> dv;
  dv.resize(nVar);
  for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
  for (int ivar=0;ivar<3;ivar++) {
    double offset = fMin_1[cls][ivar];
    double scale  = 1.0/(fMax_1[cls][ivar]-fMin_1[cls][ivar]);
    iv[indicesPut.at(ivar)] = (dv[ivar]-offset)*scale * 2 - 1;
  }
}

//_______________________________________________________________________
inline void ReadMLPDYQ6Type6::InitTransform()
{
  InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLPDYQ6Type6::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
  Transform_1( iv, sigOrBgd );
}
