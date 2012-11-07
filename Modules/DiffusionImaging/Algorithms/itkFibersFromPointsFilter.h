/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/
#ifndef itkFibersFromPointsFilter_h
#define itkFibersFromPointsFilter_h

// MITK
#include <mitkPlanarEllipse.h>
#include <mitkFiberBundleX.h>

// ITK
#include <itkProcessObject.h>

// VTK
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPolyLine.h>

using namespace std;

namespace itk{

class FibersFromPointsFilter : public ProcessObject
{
public:
    typedef FibersFromPointsFilter Self;
    typedef ProcessObject Superclass;
    typedef SmartPointer< Self > Pointer;
    typedef SmartPointer< const Self > ConstPointer;
    typedef vector< vector< mitk::PlanarEllipse::Pointer > > FiducialListType;
    typedef mitk::FiberBundleX::Pointer FiberType;
    typedef vector< mitk::FiberBundleX::Pointer > FiberContainerType;

    itkNewMacro(Self)
    itkTypeMacro( FibersFromPointsFilter, ProcessObject )

    void GenerateData();

    virtual void Update(){
        this->GenerateData();
    }

    void SetFiducials(FiducialListType fiducials){ m_Fiducials = fiducials; }
    FiberContainerType GetFiberBundles(){ return m_FiberBundles; }
    itkSetMacro(Density, int)
    itkSetMacro(FiberSampling, int)
    itkSetMacro(Tension, double)
    itkSetMacro(Continuity, double)
    itkSetMacro(Bias, double)

protected:

    FibersFromPointsFilter();
    virtual ~FibersFromPointsFilter();
    void GeneratePoints();

    FiducialListType    m_Fiducials;
    FiberContainerType  m_FiberBundles;
    int                 m_Density;
    int                 m_FiberSampling;
    double              m_Tension;
    double              m_Continuity;
    double              m_Bias;

    vector< mitk::Vector2D > m_2DPoints;
};
}

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkFibersFromPointsFilter.cpp"
#endif

#endif