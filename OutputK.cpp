
#include"csv_MatrixXd_IO.h"
#include"InputDate.h"


using namespace std;
using namespace Eigen;

int main1()
{
    ifstream in("F:\\Cfile\\OutputFile\\example.txt");
    string line;
    ofstream NodeFile;
    NodeFile.open("F:\\Cfile\\OutputFile\\NodeFile.txt");
    if (!NodeFile) return 0;
    ofstream ElaFile;
    ElaFile.open("F:\\Cfile\\OutputFile\\MatElaFile.txt");
    if (!ElaFile) return 0;
    ofstream PlaFile;
    PlaFile.open("F:\\Cfile\\OutputFile\\MatPlaFile.txt");
    if (!PlaFile) return 0;
    ofstream EleSFile;
    EleSFile.open("F:\\Cfile\\OutputFile\\EleSFile.txt");
    if (!EleSFile) return 0;
    ofstream MasterNodeFile;
    MasterNodeFile.open("F:\\Cfile\\OutputFile\\MasterNodeFile.txt");
    if (!MasterNodeFile) return 0;
    ofstream SlaveNodeFile;
    SlaveNodeFile.open("F:\\Cfile\\OutputFile\\SlaveNodeFile.txt");
    if (!SlaveNodeFile) return 0;
    ofstream ContactFile;
    ContactFile.open("F:\\Cfile\\OutputFile\\ContactFile.txt");
    if (!ContactFile) return 0;
    ofstream PartFile;
    PartFile.open("F:\\Cfile\\OutputFile\\PartFile.txt");
    if (!PartFile) return 0;
    //用不到的数据如下:
    ofstream SecSolidFile;
    SecSolidFile.open("F:\\Cfile\\OutputFile\\SecSolidFile.txt");
    if (!SecSolidFile) return 0;
    ofstream BoundaryFile;
    BoundaryFile.open("F:\\Cfile\\OutputFile\\BoundaryFile.txt");
    if (!BoundaryFile) return 0;

    int I = 0;
    int ElaLineID = 0;
    int PlaLineID = 0;
    int EleSLineID = 0;
    int ContactLineID = 0;
    int PartLineID = 0;
    int MasterNodeLineID = 0;
    int SlaveNodeLineID = 0;

    while (getline(in, line))
    {
        /*  line_process(line);
          if (line.empty()) continue;*/
        if (line == "*NODE")
        {
            I = 1;
            continue;
        }
        if (I == 1)
        {
            NodeFile << line << endl;
            vector<string> tmp_node;
            ifstream innode("F:\\Cfile\\OutputFile\\NODEFile.txt");
            string NodeLine;
            while (getline(innode, NodeLine, '\n'))
            {
                tmp_node.push_back(NodeLine + "\n");
            }
            ofstream OutNode("F:\\Cfile\\OutputFile\\OutNode.txt");
            vector<string>::iterator siter = tmp_node.begin();
            copy(tmp_node.begin(), tmp_node.end() - 1, ostream_iterator<string>(OutNode));
            innode.close();
            OutNode.close();
        }

        //材料部分最终输出文件见最下方，OutElaFile，OutPlaFile。
        if (line == "*MAT_ELASTIC")
        {
            I = 2;
            continue;
        }
        if (I == 2)
        {
            ElaLineID++;
            if (ElaLineID == 1 || ElaLineID == 3)
            {
                continue;
            }
            ElaFile << line << endl;
            vector<string> tmp_Ela;
            ifstream inEla("F:\\Cfile\\OutputFile\\MatElaFile.txt");
            string Elaline;
            while (getline(inEla, Elaline, '\n'))
            {
                tmp_Ela.push_back(Elaline + "\n");
            }
            ofstream OutEla("F:\\Cfile\\OutputFile\\OutEla.txt");
            vector<string>::iterator siter = tmp_Ela.begin();
            copy(tmp_Ela.begin(), tmp_Ela.end() - 1, ostream_iterator<string>(OutEla));
            inEla.close();
            OutEla.close();
        }

        if (line == "*MAT_PLASTIC_KINEMATIC")
        {
            I = 3;
            continue;
        }
        if (I == 3)
        {
            PlaLineID++;
            if (PlaLineID == 1 || PlaLineID == 3)
            {
                continue;
            }
            PlaFile << line << endl;
            vector<string> tmp_Pla;
            ifstream inPla("F:\\Cfile\\OutputFile\\MatPlaFile.txt");
            string Plaline;
            while (getline(inPla, Plaline, '\n'))
            {
                tmp_Pla.push_back(Plaline + "\n");
            }
            ofstream OutPla("F:\\Cfile\\OutputFile\\OutPla.txt");
            vector<string>::iterator siter = tmp_Pla.begin();
            copy(tmp_Pla.begin(), tmp_Pla.end() - 1, ostream_iterator<string>(OutPla));
            inPla.close();
            OutPla.close();
        }

        if (line == "*PART")
        {
            I = 4;
            continue;
        }
        if (I == 4)
        {
            PartLineID++;
            if (PartLineID == 1 || PartLineID == 2 || PartLineID == 4 || PartLineID == 5 || PartLineID == 7 ||
                PartLineID == 8 || PartLineID == 10 || PartLineID == 11 || PartLineID == 13 ||
                PartLineID == 14 || PartLineID == 16 || PartLineID == 17 || PartLineID == 19 || PartLineID == 20)
            {
                continue;
            }
            PartFile << line << endl;
            vector<string> tmp_Part;
            ifstream inPart("F:\\Cfile\\OutputFile\\PartFile.txt");
            string Partline;
            while (getline(inPart, Partline, '\n'))
            {
                tmp_Part.push_back(Partline + "\n");
            }
            ofstream OutPart("F:\\Cfile\\OutputFile\\OutPart.txt");
            vector<string>::iterator siter = tmp_Part.begin();
            copy(tmp_Part.begin(), tmp_Part.end() - 1, ostream_iterator<string>(OutPart));
            inPart.close();
            OutPart.close();
        }

        if (line == "*SECTION_SOLID")
        {
            I = 5;
            continue;
        }
        if (I == 5)
        {
            SecSolidFile << line << endl;
            vector<string> tmp_SecSolid;
            ifstream inSecSolid("F:\\Cfile\\OutputFile\\SecSolidFile.txt");
            string SecSolidline;
            while (getline(inSecSolid, SecSolidline, '\n'))
            {
                tmp_SecSolid.push_back(SecSolidline + "\n");
            }
            ofstream OutSecSolid("F:\\Cfile\\OutputFile\\OutSecSolid.txt");
            vector<string>::iterator siter = tmp_SecSolid.begin();
            copy(tmp_SecSolid.begin(), tmp_SecSolid.end() - 1, ostream_iterator<string>(OutSecSolid));
            inSecSolid.close();
            OutSecSolid.close();
        }

        if (line == "*SET_SEGMENT")
        {
            I = 6;
            continue;
        }
        if (I == 6)
        {
            MasterNodeLineID++;
            if (MasterNodeLineID < 4)
            {
                continue;
            }
            MasterNodeFile << line << endl;
            vector<string> tmp_MasterNode;
            ifstream inMasterNode("F:\\Cfile\\OutputFile\\MasterNodeFile.txt");
            string MasterNodeline;
            while (getline(inMasterNode, MasterNodeline, '\n'))
            {
                tmp_MasterNode.push_back(MasterNodeline + "\n");
            }
            ofstream OutMasterNode("F:\\Cfile\\OutputFile\\OutMasterNode.txt");
            vector<string>::iterator siter = tmp_MasterNode.begin();
            copy(tmp_MasterNode.begin(), tmp_MasterNode.end() - 1, ostream_iterator<string>(OutMasterNode));
            inMasterNode.close();
            OutMasterNode.close();
        }

        //contact最终输出文件是 ContactFile。
        if (line == "*CONTACT_AUTOMATIC_NODES_TO_SURFACE_ID")
        {
            I = 7;
            continue;
        }
        if (I == 7)
        {
            ContactLineID++;
            if (ContactLineID == 4)
            {
                ContactFile << line << endl;
            }
            /* vector<string> tmp_Contact;
             ifstream inContact("F:\\Cfile\\OutputFile\\ContactFile.txt");
             string Contactline;
             while (getline(inContact, Contactline, '\n'))
             {
                 tmp_Contact.push_back(Contactline + "\n");
             }
             ofstream OutContact("F:\\Cfile\\OutputFile\\OutContact.txt");
             vector<string>::iterator siter = tmp_Contact.begin();
             copy(tmp_Contact.begin(), tmp_Contact.end() - 1, ostream_iterator<string>(OutContact));
               inContact.close();
               OutContact.close();*/
        }

        if (line == "*ELEMENT_SOLID")
        {
            I = 8;
            continue;
        }
        if (I == 8)
        {
            EleSLineID++;
            if (EleSLineID > 2 && EleSLineID < 6)
            {
                continue;
            }
            EleSFile << line << endl;
            vector<string> tmp_EleS;
            ifstream inEleS("F:\\Cfile\\OutputFile\\EleSFile.txt");
            string EleSline;
            while (getline(inEleS, EleSline, '\n'))
            {
                tmp_EleS.push_back(EleSline + "\n");
            }
            ofstream OutEleS("F:\\Cfile\\OutputFile\\OutEleS.txt");
            vector<string>::iterator siter = tmp_EleS.begin();
            /* vector<string>::iterator siter2 = tmp_EleS.end();*/
           /*  tmp_EleS.erase(tmp_EleS.begin()+1);*/
            copy(tmp_EleS.begin(), tmp_EleS.end() - 1, ostream_iterator<string>(OutEleS));
            inEleS.close();
            OutEleS.close();
        }


        if (line == "*SET_NODE_LIST")
        {
            I = 9;
            continue;
        }
        if (I == 9)
        {
            SlaveNodeLineID++;
            if (SlaveNodeLineID < 4)
            {
                continue;
            }
            SlaveNodeFile << line << endl;
            vector<string> tmp_SlaveNode;
            ifstream inSlaveNode("F:\\Cfile\\OutputFile\\SlaveNodeFile.txt");
            string SlaveNodeline;
            while (getline(inSlaveNode, SlaveNodeline, '\n'))
            {
                tmp_SlaveNode.push_back(SlaveNodeline + "\n");
            }
            ofstream OutSlaveNode("F:\\Cfile\\OutputFile\\OutSlaveNode.txt");
            vector<string>::iterator siter = tmp_SlaveNode.begin();
            copy(tmp_SlaveNode.begin(), tmp_SlaveNode.end() - 1, ostream_iterator<string>(OutSlaveNode));
            inSlaveNode.close();
            OutSlaveNode.close();
        }

        if (line == "*BOUNDARY_SPC_NODE")
        {
            I = 10;
            continue;
        }
        if (I == 10)
        {
            BoundaryFile << line << endl;
            vector<string> tmp_Boundary;
            ifstream inBoundary("F:\\Cfile\\OutputFile\\BoundaryFile.txt");
            string Boundaryline;
            while (getline(inBoundary, Boundaryline, '\n'))
            {
                tmp_Boundary.push_back(Boundaryline + "\n");
            }
            ofstream OutBoundary("F:\\Cfile\\OutputFile\\OutBoundary.txt");
            vector<string>::iterator siter = tmp_Boundary.begin();
            copy(tmp_Boundary.begin(), tmp_Boundary.end() - 1, ostream_iterator<string>(OutBoundary));
            inBoundary.close();
            OutBoundary.close();
        }


    }

    //材料部分最终输出文件
    string lineSpace = " ";
    string ElaLine2;
    ifstream InElaFile("F:\\Cfile\\OutputFile\\OutEla.txt");
    ofstream OutElaFile("F:\\Cfile\\OutputFile\\OutElaFile.txt");
    while (getline(InElaFile, ElaLine2))
    {
        ElaLine2 = ElaLine2.insert(10, lineSpace);
        /*cout << ElaLine2 << endl;*/
        OutElaFile << ElaLine2 << endl;
    }

    string PlaLine2;
    ifstream InPlaFile("F:\\Cfile\\OutputFile\\OutPla.txt");
    ofstream OutPlaFile("F:\\Cfile\\OutputFile\\OutPlaFile.txt");
    while (getline(InPlaFile, PlaLine2))
    {
        PlaLine2 = PlaLine2.insert(10, lineSpace);
        PlaLine2.erase(0, PlaLine2.find_first_not_of(" "));
        cout << PlaLine2;
        OutPlaFile << PlaLine2 << endl;
    }

    in.close();
    NodeFile.close();
    ElaFile.close();
    PlaFile.close();
    EleSFile.close();
    MasterNodeFile.close();
    SlaveNodeFile.close();
    ContactFile.close();
    PartFile.close();
    SecSolidFile.close();
    BoundaryFile.close();
    InElaFile.close();
    OutElaFile.close();
    InPlaFile.close();
    OutPlaFile.close();

};

int main()
{
    //part,section 信息
    class Part
    {
    public:
        int Pid;
        int Sid;
        int Mid;
    };
    class sectionbeam
    {
    public:
        int secidbeam;
        double TS;
        double TT;
    };
    class sectionshell
    {
    public:
        int secidshell;
        double T1;
        double T2;
        double T3;
        double T4;
    };
    class lsmap
    {
    public:
        map<int, Part > AllPart;
        map<int, sectionbeam>AllSectionbeam;
        map<int, sectionshell>AllSectionshell;
    };
    //Part信息
    Matrix<int, Dynamic, Dynamic>PartImformation = LinearMSTMMSolver::openDataInt("F:\\Cfile\\OutputFile\\OutPart.txt");
    Part* IP = new Part;
    lsmap* ls = new lsmap;
    /*cout << PartImformation;*/
    for (int i = 0; i < PartImformation.rows(); i++)
    {
        (*IP).Pid = PartImformation(i, 0);
        (*IP).Sid = PartImformation(i, 1);
        (*IP).Mid = PartImformation(i, 2);
        (*ls).AllPart.insert(make_pair((*IP).Pid, (*IP)));
    };

    //Beam信息
    Matrix<int, Dynamic, Dynamic>SecBImformation1 = LinearMSTMMSolver::openDataInt("F:\\Cfile\\SECTION_BEAM.txt");
    Matrix<double, Dynamic, Dynamic>SecBImformation2 = LinearMSTMMSolver::openData("F:\\Cfile\\SECTION_BEAM.txt");
    sectionbeam* ISB = new sectionbeam;
    /*lsmap* ls = new lsmap;*/
    for (int i = 0; i < SecBImformation2.rows(); i++)
    {
        (*ISB).secidbeam = SecBImformation1(i, 0);
        (*ISB).TS = SecBImformation2(i, 5);
        (*ISB).TT = SecBImformation2(i, 7);
        (*ls).AllSectionbeam.insert(make_pair((*ISB).secidbeam, (*ISB)));
    };
    
    //Shell信息
    Matrix<int, Dynamic, Dynamic>SecSHImformation1 = LinearMSTMMSolver::openDataInt("F:\\Cfile\\SECTION_SHELL.txt");
    Matrix<double, Dynamic, Dynamic>SecSHImformation2 = LinearMSTMMSolver::openData("F:\\Cfile\\SECTION_SHELL.txt");
    sectionshell* ISSH = new sectionshell;
    /*lsmap* ls = new lsmap;*/
    for (int i = 0; i < SecSHImformation2.rows(); i++)
    {
        (*ISSH).secidshell = SecSHImformation1(i, 0);
        (*ISSH).T1 = SecSHImformation2(i, 1);
        (*ISSH).T2 = SecSHImformation2(i, 2);
        (*ISSH).T3 = SecSHImformation2(i, 3);
        (*ISSH).T4 = SecSHImformation2(i, 4);
        (*ls).AllSectionshell.insert(make_pair((*ISSH).secidshell, (*ISSH)));

    };
      
    //节点信息
    Matrix<double, Dynamic, Dynamic>NodeImformation1 = LinearMSTMMSolver::openData("F:\\Cfile\\OutputFile\\OutNode.txt");
    Matrix<int, Dynamic, Dynamic>NodeImformation2 = LinearMSTMMSolver::openDataInt("F:\\Cfile\\OutputFile\\OutNode.txt");
    InputNode* INN = new InputNode;
    InputAllDate* IAD = new InputAllDate;
    for (int i = 0; i < NodeImformation1.rows(); i++)
    {
        (*INN).NodeID = NodeImformation2(i, 0);
        (*INN).NodeCoordinates = NodeImformation1.row(i).rightCols(3).adjoint();    
       /* cout << (*INN).NodeCoordinates << endl;*/
        (*IAD).InputAllNode.insert(make_pair((*INN).NodeID, (*INN)));
    };
    /*cout << (*IAD).InputAllNode[2].NodeCoordinates;*/

    //实体单元信息
    Matrix<int, Dynamic, Dynamic>EleSoImformation = LinearMSTMMSolver::openDataInt("F:\\Cfile\\OutputFile\\OutEleS.txt");
   /* cout << EleSoImformation;*/
    InputElement* InESo = new InputElement;
    /*  InputAllDate* IAD = new InputAllDate;*/
    //cout<< EleSoImformation.row(1).rightCols(8).adjoint();
    for (int i = 0; i < EleSoImformation.rows(); i++)
    {
        (*InESo).ElementID = EleSoImformation(i, 0);      /* cout << (*INE_SO).ElementID << endl;*/
        (*InESo).ElementTypeID = 0;
        (*InESo).MaterialID = (*ls).AllPart[EleSoImformation(i, 1)].Mid;
        (*InESo).ElementNodeID.resize(8, 1);
        (*InESo).ElementNodeID = EleSoImformation.row(i).rightCols(8).adjoint();
        (*InESo).ElementNodeCoordinates.resize(8, 3);
        for (int J = 0; J < 8; J++)
        {
            (*InESo).ElementNodeCoordinates.row(J) = (*IAD).InputAllNode[(*InESo).ElementNodeID(J, 0)].NodeCoordinates.adjoint();
        }
       /* cout << (*InESo).ElementNodeCoordinates<<endl ;*/
        (*IAD).InputAllElement.insert(make_pair((*InESo).ElementID, (*InESo)));
    }

   

    //壳单元信息
    Matrix<int, Dynamic, Dynamic>EleShImformation = LinearMSTMMSolver::openDataInt("F:\\Cfile\\ELEMENT_SHELL.txt");
    InputElement* InESh = new InputElement;
    /*  InputAllDate* IAD = new InputAllDate;*/
    for (int i = 0; i < EleShImformation.rows(); i++)
    {
        (*InESh).ElementID = EleShImformation(i, 0);      /* cout << (*INE).ElementID << endl;*/
        (*InESh).ElementTypeID = 1;
        (*InESh).MaterialID = (*ls).AllPart[EleShImformation(i, 1)].Mid;
        (*InESh).ElementNodeID.resize(4, 1);
        (*InESh).ElementNodeID = EleShImformation.row(i).rightCols(4).adjoint();
        (*InESh).ElementNodeCoordinates.resize(4, 3);
        for (int A = 0; A < 4; A++)
        {
            (*InESh).ElementNodeCoordinates.row(A) = (*IAD).InputAllNode[(*InESh).ElementNodeID(A, 0)].NodeCoordinates.adjoint();
        }
        (*InESh).ShellGeometricParameter(0, 0) = (*ls).AllSectionshell[(*ls).AllPart[EleShImformation(i, 1)].Sid].T1;
        (*InESh).ShellGeometricParameter(1, 0) = (*ls).AllSectionshell[(*ls).AllPart[EleShImformation(i, 1)].Sid].T2;
        (*InESh).ShellGeometricParameter(2, 0) = (*ls).AllSectionshell[(*ls).AllPart[EleShImformation(i, 1)].Sid].T3;
        (*InESh).ShellGeometricParameter(3, 0) = (*ls).AllSectionshell[(*ls).AllPart[EleShImformation(i, 1)].Sid].T4;
       /* cout << (*InESh).ShellGeometricParameter << endl;*/
            (*IAD).InputAllElement.insert(make_pair((*InESh).ElementID, (*InESh)));
    }

    //梁单元信息
    Matrix<int, Dynamic, Dynamic>EleBImformation = LinearMSTMMSolver::openDataInt("F:\\Cfile\\ELEMENT_BEAM.txt");
    InputElement* InEB = new InputElement;
    /*  InputAllDate* IAD = new InputAllDate;*/
    for (int i = 0; i < EleBImformation.rows(); i++)
    {
        (*InEB).ElementID = EleBImformation(i, 0);      /* cout << (*INE).ElementID << endl;*/
        (*InEB).ElementTypeID = 2;
        (*InEB).MaterialID = (*ls).AllPart[EleBImformation(i, 1)].Mid;
        (*InEB).ElementNodeID.resize(2, 1);
        (*InEB).ElementNodeID = EleBImformation.row(i).rightCols(2).adjoint();
        (*InEB).ElementNodeCoordinates.resize(2, 3);
        for (int j = 0; j < 2; j++)
        {
            (*InEB).ElementNodeCoordinates.row(j) = (*IAD).InputAllNode[(*InEB).ElementNodeID(j, 0)].NodeCoordinates.adjoint();
        }
        (*InEB).ElementGeometricParameter(0, 0) = (*ls).AllSectionbeam[(*ls).AllPart[EleBImformation(i, 1)].Sid].TS;                              //只有宽和高目前，SECTION文件里， ts1和ts2是宽  
        (*InEB).ElementGeometricParameter(1, 0) = (*ls).AllSectionbeam[(*ls).AllPart[EleBImformation(i, 1)].Sid].TT;
         /* cout << (*InEB).ElementGeometricParameter<<endl;*/
              (*IAD).InputAllElement.insert(make_pair((*InEB).ElementID, (*InEB)));
    }

    //1号弹性材料信息
    Matrix<double, Dynamic, Dynamic>MaEImformation1 = LinearMSTMMSolver::openData("F:\\Cfile\\OutputFile\\OutElaFile.txt");
    Matrix<int, Dynamic, Dynamic>MaEImformation2 = LinearMSTMMSolver::openDataInt("F:\\Cfile\\OutputFile\\OutElaFile.txt");
    /*cout << MaEImformation1 << endl ;*/
    InputMaterial* InME = new InputMaterial;
    /*  InputAllDate* IAD = new InputAllDate;*/
    for (int i = 0; i < MaEImformation1.rows(); i++)
    {
        (*InME).MaterialID = MaEImformation2(i, 0);              /*cout << (*InME).MaterialID << endl;*/
        (*InME).MaterialType = 1;
        (*InME).Density = MaEImformation1(i, 1);
        (*InME).ElasticModulu = MaEImformation1(i, 2);
        (*InME).PoissonsRatio= MaEImformation1(i, 3);

        (*IAD).InputAllMaterial.insert(make_pair((*InME).MaterialID, (*InME)));
    }
   /* cout << (*IAD).InputAllMaterial[6].Density;*/

    ////24号弹塑性材料信息
    //Matrix<double, Dynamic, Dynamic>MaPImformation1 = LinearMSTMMSolver::openData("F:\\Cfile\\MAT_PIECEWISE_LINEAR_PLASTICITY.txt");
    //Matrix<int, Dynamic, Dynamic>MaPImformation2 = LinearMSTMMSolver::openDataInt("F:\\Cfile\\MAT_PIECEWISE_LINEAR_PLASTICITY.txt");
    //  /*cout << MaPImformation1 << endl << MaPImformation2;*/
    //InputMaterial* InMP = new InputMaterial;
    ///*  InputAllDate* IAD = new InputAllDate;*/
    //for (int i = 0; i < MaPImformation1.rows(); i++)
    //{
    //    (*InMP).MaterialID = MaPImformation2(i, 0);              
    //    (*InMP).MaterialType = 2;   //待定
    //    (*InMP).Density = MaPImformation1(i, 1);
    //    (*InMP).ElasticModulu = MaPImformation1(i, 2);
    //    (*InMP).PoissonsRatio = MaPImformation1(i, 3);
    //    (*InMP).InitialYieldStress = MaPImformation1(i, 4);
    //    (*InMP).TangentialModulus = MaPImformation1(i, 5);
    //   // (*InMP).MixedHardeningParameter = 混合硬化参数,3号塑性材料。BETA Hardening parameter, 0-1.
    //    (*IAD).InputAllMaterial.insert(make_pair((*InMP).MaterialID, (*InMP)));
    //}

    //3号塑性材料信息
    Matrix<double, Dynamic, Dynamic>MaPImformation1 = LinearMSTMMSolver::openData("F:\\Cfile\\OutputFile\\OutPlaFile.txt");
    Matrix<int, Dynamic, Dynamic>MaPImformation2 = LinearMSTMMSolver::openDataInt("F:\\Cfile\\OutputFile\\OutPlaFile.txt");
   /* cout << MaPImformation1 << endl ;*/
    //cout << MaPImformation2 << endl;
    InputMaterial* InMP = new InputMaterial;
    /*  InputAllDate* IAD = new InputAllDate;*/
    for (int i = 0; i < MaPImformation1.rows(); i++)
    {
        (*InMP).MaterialID = MaPImformation2(i, 0);              
        (*InMP).MaterialType = 2;   //待定
        (*InMP).Density = MaPImformation1(i, 1);
        (*InMP).ElasticModulu = MaPImformation1(i, 2);
        (*InMP).PoissonsRatio = MaPImformation1(i, 3);
        (*InMP).InitialYieldStress = MaPImformation1(i, 4);
        (*InMP).TangentialModulus = MaPImformation1(i, 5);
        (*InMP).MixedHardeningParameter = 0;  //MaPImformation1(i, 6);    //混合硬化参数,3号塑性材料。BETA Hardening parameter, 0-1.
        (*IAD).InputAllMaterial.insert(make_pair((*InMP).MaterialID, (*InMP)));
    }
    /*cout << (*IAD).InputAllMaterial[7].InitialYieldStress;*/

    //contact信息
    Matrix<int, Dynamic, Dynamic>ContactMImformation = LinearMSTMMSolver::openDataInt("F:\\Cfile\\OutputFile\\OutMasterNode.txt");
    Matrix<int, Dynamic, Dynamic>ContactSImformation = LinearMSTMMSolver::openDataInt("F:\\Cfile\\OutputFile\\OutSlaveNode.txt");
    Matrix<double, Dynamic, Dynamic>ContactImformation = LinearMSTMMSolver::openData("F:\\Cfile\\OutputFile\\ContactFile.txt");
    InputContact* InCta = new InputContact;
    /*  InputAllDate* IAD = new InputAllDate;*/
   
        (*InCta).ContactNumber = 1;
        (*InCta).FrictionJudgment = 0;
        (*InCta).StaticFrictionCoefficient = ContactImformation(0,0);
        (*InCta).DynamicFrictionCoefficient = ContactImformation(0, 1);
        for (int i = 0; i < ContactMImformation.rows(); i++)
        {
       
            (*InCta).MasterContactNode.insert(make_pair((i+1), ContactMImformation.row(i).adjoint()));
        }
        for (int i = 0; i < ContactSImformation.rows(); i++)
        {
            (*InCta).SlaveContactNode.insert(make_pair((i + 1), ContactSImformation.row(i).adjoint()));
        }
        (*IAD).InputAllContact.insert(make_pair((*InCta).ContactNumber, (*InCta)));
     
delete ISSH;
delete ISB;
delete IP;
delete ls;
delete INN;
delete IAD;
delete InESo;
delete InESh;
delete InEB;
delete InME;
delete InMP;
delete InCta;
}
