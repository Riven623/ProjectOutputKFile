#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;



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
            if(I==1)
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
               copy(tmp_node.begin(), tmp_node.end()-1, ostream_iterator<string>(OutNode));
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
                PlaLineID ++ ;
                if (PlaLineID == 1|| PlaLineID == 3)
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
                if (PartLineID == 1|| PartLineID == 2|| PartLineID == 4|| PartLineID == 5|| PartLineID == 7|| 
                    PartLineID == 8|| PartLineID == 10|| PartLineID == 11 || PartLineID == 13 || 
                    PartLineID == 14|| PartLineID == 16 || PartLineID == 17 || PartLineID == 19 || PartLineID == 20)
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
                if (MasterNodeLineID <4)
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
                if(ContactLineID==4)
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
                if (EleSLineID > 2&& EleSLineID<6)
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
                copy(tmp_EleS.begin(), tmp_EleS.end()-1, ostream_iterator<string>(OutEleS));
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
                if (SlaveNodeLineID<4)
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
          cout << PlaLine2 ;
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
      
}

   

 

             

