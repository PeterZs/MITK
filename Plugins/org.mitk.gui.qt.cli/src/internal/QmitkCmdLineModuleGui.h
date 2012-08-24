/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) University College London (UCL).
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef QmitkCmdLineModuleGui_h
#define QmitkCmdLineModuleGui_h

#include <QBuffer>
#include <QUiLoader>

#include <ctkCmdLineModuleReference.h>
#include <ctkCmdLineModuleFrontendQtGui.h>

namespace mitk
{
  class DataStorage;
}
class QmitkCmdLineModuleGuiPrivate;

/**
 * \class QmitkCmdLineModuleGui
 * \brief Derived from ctkCmdLineModuleQtGui to implement an MITK specific command line module,
 * that has access to the mitk::DataStorage, and also instantiates QmitkDataStorageComboBox
 * for any "imageInputWidget" type, and also provides QmitkDataStorageComboBox.xsl to override
 * the standard CTK xslt transformation.
 * \author Matt Clarkson (m.clarkson@ucl.ac.uk)
 * \ingroup org_mitk_gui_qt_cli_internal
 * \sa QmitkCmdLineModuleFactoryGui
 */
class QmitkCmdLineModuleGui : public ctkCmdLineModuleFrontendQtGui
{
  Q_OBJECT

public:
  QmitkCmdLineModuleGui(const mitk::DataStorage* dataStorage, const ctkCmdLineModuleReference& moduleRef);
  virtual ~QmitkCmdLineModuleGui();

protected:

  /**
   * \brief Virtual getter.
   * \see ctkCmdLineModuleFrontendQtGui::uiLoader()
   */
  virtual QUiLoader* uiLoader() const;

  /**
   * \brief Virtual getter.
   * \see ctkCmdLineModuleFrontendQtGui::xslTransform()
   */
  virtual ctkCmdLineModuleXslTransform* xslTransform() const;

private:

  QScopedPointer<QmitkCmdLineModuleGuiPrivate> d;

}; // end class

#endif // QmitkCmdLineModuleGui_h
