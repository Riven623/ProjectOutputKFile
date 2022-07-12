#pragma once

#include "IClude.h"

class InputMaterial
{
public:
    int MaterialID;//��ʾ�ڼ��ֲ���.(MID)
    int MaterialType;//��������1�����ԡ�2����˫���ԡ�3���������
    double Density;//�ܶ� (RO)
    double ElasticModulu;//����ģ�� (E)
    double PoissonsRatio;//���ɱ� (PR)
    double InitialYieldStress=0;//��ʼ����Ӧ�� (SIGY)
    double MixedHardeningParameter=0;//���Ӳ������  ��EH /ET��
    double TangentialModulus=0;//����ģ�� (ETAN)
    //Matrix<double, Dynamic, 2> StrainStressCurve;//�����Բ���Ӧ��Ӧ���������һ����Ӧ�䣬�ڶ���Ϊ��Ӧ��Ӧ��,�����ϲ��Ƕ�����ʱ�����û�д˲�������Ϊ0
//˫���ԡ����ǿ����Mises ����׼��J2��������
    InputMaterial() = default;
    InputMaterial(int i);
};


class InputNode//�ڵ��ʼλ�ơ��ٶȡ����ٶ�
{
public:
    int NodeID;//�ڵ��� (NID)
    Matrix<double, 3, 1> NodeCoordinates;//���꣨x,y,z����ֵ
    Matrix<double, Dynamic, 1> NodeAcceleration;//ǰ���зֱ�Ϊ��x,y,z���ķ����ϵ��߼��ٶ�ֵ�������зֱ�Ϊ��x,y,z���ķ����ϵĽǼ��ٶ�ֵ��Dynamic��������Ϊ6��ʵ��Ϊ3
    Matrix<double, Dynamic, 1> NodeVelocity;//ǰ���зֱ�Ϊ��x,y,z���ķ����ϵ����ٶ�ֵ�������зֱ�Ϊ��x,y,z���ķ����ϵĽ��ٶ�ֵ
    Matrix<double, Dynamic, 1> NodeDisplacement;//ǰ���зֱ�Ϊ��x,y,z���ķ����ϵ����ٶ�ֵ�������зֱ�Ϊ��x,y,z���ķ����ϵĽ��ٶ�ֵ
    InputNode() = default;
    InputNode(int i);
};

 class InputElement 
{
public:
    int ElementID;//��Ԫ��� (EID)
    int ElementTypeID;//��Ԫ���ͱ�ţ�0��ʾ8�ڵ�ʵ�壬1����4�ڵ�ǣ�2����2�ڵ�ŷ����
    int MaterialID;//���ϱ��,��ʾ�ڼ��ֲ��� (MID)
    Matrix<double, Dynamic, 3> ElementNodeCoordinates;//xyz���ꣻ�Լ�ƴ����Dynamic,�����ڽڵ���������
    Matrix<int, Dynamic, 1> ElementNodeID;//�ڵ��ţ�ElementGeometricParameter;Dynamic,�����ڽڵ�����NID��
    Matrix<double, 2, 1>  ElementGeometricParameter;//����Ԫ�ĳ�����������
    //Matrix<int, 1, 3> ReferencePoint;//����Ԫ�òο������꣬ͳһ�ģ������
    //Matrix<double, 3, 1> ElementBodyForce;//x��y��z��������������������������Ȳ���
    Matrix<double,4, 1> ShellGeometricParameter;//  �ǵĺ�Ⱦ��� ��sectionshell t1-t4)
    InputElement() = default;
 
    InputElement(int i);
};

class InputConstraint
{
public:
    int ConstraintType;//0��ʾ����λ�ƣ�1��ʾ�����غ�
    int ConstraintNodeID;//Լ���Ľڵ��
    Matrix<int, Dynamic,1 > ConstraintNodeDofID;//�洢��Լ�������ɶȣ�xyz����Ӧת�Ƿֱ�Ϊ1��2��3��4��5��6������Dynamic����Ϊ��������λ�Ƶĸ�����ʵ�����Ϊ3���������Ϊ6
    Matrix<double, Dynamic, 1> NodeExternalConstraint;//����ֱ�ֱ�Ϊ����Լ����������ɶ��ϵ��غɣ���ȫԼ�� ����0��
    InputConstraint() = default;
    InputConstraint(int i);
};

class InputCouplingPoint
{
public:
    int CouplingPointID; //�ڵ�����ɶ���ȫ��ȫһ�µĽڵ㼯������Լ��
    vector<int> CPNodeID;//��ϵĽڵ��� ����һ������Ϊ���ڵ���
    int CPDof;//��ϵ����ɶȣ�1-6�����ֱ�������������λ�ơ����������ת��
    InputCouplingPoint() = default;
    InputCouplingPoint(int i);
};

class InputCouplingEquation
{
public:
    int CouplingEquationID; //Լ�����̱��
    Matrix<int, 14, 1> CE;
    /*��һ��ֵΪԼ�����̳������ڶ���Ϊ��һ��Լ���ڵ��ţ�������Ϊ�ýڵ�����ɶȣ�1��2��3��4��5��6�������ĸ�Ϊ�����ɶȵ�ϵ����
                      *�����Ϊ�ڶ���Լ���ڵ��ţ�������Ϊ�ýڵ�����ɶȣ�1��2��3��4��5��6�������߸�Ϊ�����ɶȵ�ϵ����
                      �ڰ˸�Ϊ������Լ���ڵ��ţ��ھŸ�Ϊ�ýڵ�����ɶȣ�1��2��3��4��5��6������10��14��Ϊ�����ɶȵģ�10ϵ����11�ڵ��š�12���ɶȣ�1��2��3����13�ڵ��š�14���ɶȣ�1��2��3����
                      *CE,1,0,626,UX,1,2328,UX,-1,1,ROTY,-ABS(NZ(626)-NZ(2328))
     */
    InputCouplingEquation() = default;
    InputCouplingEquation(int i);
};

class InputContact
{
public:
    int ContactNumber;//�Ӵ��Ա��
    double StaticFrictionCoefficient, DynamicFrictionCoefficient;//Ħ��ϵ��
    int FrictionJudgment;//0��ʾ��Ħ����1��ʾ��Ħ��
    double NormalPenaltyFactor, TangentialPenaltyFactor=1, NREps = 1.E-6;//������,NR�����ľ���
    map<int,Matrix<int, Dynamic, 1>> MasterContactNode;//��һ��intΪ��Ԫ�ţ�MatrixΪ��Ԫ�Ӵ�����ڵ��
    map<int, Matrix<int, Dynamic, 1>> SlaveContactNode;//int��MatrixΪ��Ԫ����ڵ��,�ڵ��Ҫ����ʱ�����
    InputContact() = default;
    InputContact(int i);
};

class DynamicCalculation
{
public:
    double ComputingTime;//������ʱ��
   double TimeIncrement;//����
    DynamicCalculation() = default;
    DynamicCalculation(int i);
};

class InputAllDate
{
public:
    map<int,InputElement > InputAllElement;//ÿ��pair�е�key�洢��Ԫ��ţ�value�洢�õ�Ԫ��������Ϣ
    map<int, InputMaterial> InputAllMaterial;//ÿ��pair�е�key�洢���ϱ�ţ�value�洢�ò��ϵ�������Ϣ
    multimap<int,InputConstraint> InputAllConstraint;//ÿ��pair�е�key�洢Լ���ڵ��ţ�value�洢�ýڵ������Լ����Ϣ
    map<int, InputContact> InputAllContact;//ÿ��pair�е�key�洢�Ӵ��Ա�ţ�value�洢�ýӴ��Ե�������Ϣ
    map<int, InputNode> InputAllNode;//ÿ��pair�е�key  �洢�ڵ��ţ�value�洢�ýڵ��������Ϣ
    map<int, InputCouplingPoint> InputAllCP;
    map<int, InputCouplingEquation> InputAllCE;
    double AF, BT;//��������ϵ��
    InputAllDate() = default;
    InputAllDate(int i);
};
