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

#include "mitkTimeGridHelper.h"

#include "itkExceptionObject.h"

bool mitk::TimeGridIsMonotonIncreasing(const mitk::ModelBase::TimeGridType timeGrid)
{
    mitk::ModelBase::TimeGridType::ValueType lastTime = itk::NumericTraits<mitk::ModelBase::TimeGridType::ValueType>::NonpositiveMin();

    for(mitk::ModelBase::TimeGridType::const_iterator posTime = timeGrid.begin(); posTime != timeGrid.end(); ++posTime)
    {
      if (lastTime>*posTime) return false;
    }

    return true;
};

mitk::ModelBase::ModelResultType mitk::InterpolateSignalToNewTimeGrid(const ModelBase::ModelResultType& inputSignal, const ModelBase::TimeGridType& inputGrid, const ModelBase::TimeGridType& outputGrid)
{
    mitk::ModelBase::ModelResultType result(outputGrid.GetSize());
    if (! inputSignal.GetSize())
    {
      return result;
    }

    if (inputSignal.GetSize() != inputGrid.GetSize())
    {
      itkGenericExceptionMacro("Input signal and input time grid have not the same size.");
    }

    mitk::ModelBase::ModelResultType::ValueType lastValue = inputSignal[0];
    mitk::ModelBase::TimeGridType::ValueType lastTime = itk::NumericTraits<mitk::ModelBase::TimeGridType::ValueType>::NonpositiveMin();

    mitk::ModelBase::TimeGridType::const_iterator posITime = inputGrid.begin();
    mitk::ModelBase::ModelResultType::const_iterator posValue = inputSignal.begin();
    mitk::ModelBase::ModelResultType::iterator posResult = result.begin();

    for(mitk::ModelBase::TimeGridType::const_iterator posOTime = outputGrid.begin(); posOTime != outputGrid.end(); ++posResult, ++posOTime)
    {
        while(*posOTime > *posITime && posITime!=inputGrid.end())
      { //forward in the input grid until the current output point
        //is between last and the current input point.
        lastValue = *posValue;
        lastTime = *posITime;
        ++posValue;
        ++posITime;
      }

      double weightLast = 1 - (*posOTime - lastTime)/(*posITime - lastTime);
      double weightNext = 1 - (*posITime - *posOTime)/(*posITime - lastTime);

      *posResult = weightLast * lastValue + weightNext * (*posValue);
    }

    return result;
};
