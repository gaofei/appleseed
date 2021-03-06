
//
// This source file is part of appleseed.
// Visit https://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2018 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_STUDIO_MAINWINDOW_FALSECOLORSWINDOW_H
#define APPLESEED_STUDIO_MAINWINDOW_FALSECOLORSWINDOW_H

// appleseed.studio headers.
#include "mainwindow/project/entityeditor.h"
#include "utility/windowbase.h"

// appleseed.foundation headers.
#include "foundation/utility/containers/dictionary.h"

// Qt headers.
#include <QObject>

// Standard headers.
#include <memory>

// Forward declarations.
namespace renderer  { class ParamArray; }
namespace renderer  { class Project; }
namespace Ui        { class FalseColorsWindow; }
class QWidget;

namespace appleseed {
namespace studio {

class FalseColorsWindow
  : public WindowBase
{
    Q_OBJECT

  public:
    // Constructor.
    explicit FalseColorsWindow(QWidget* parent);

    // Destructor.
    ~FalseColorsWindow() override;

    void initialize(
        const renderer::Project&        project,
        renderer::ParamArray&           settings,
        const foundation::Dictionary&   values);

  signals:
    void signal_applied(foundation::Dictionary values);
    void signal_accepted(foundation::Dictionary values);
    void signal_canceled(foundation::Dictionary values);

  private:
    // Not wrapped in std::unique_ptr<> to avoid pulling in the UI definition code.
    Ui::FalseColorsWindow*              m_ui;

    foundation::Dictionary              m_initial_values;
    std::unique_ptr<EntityEditor>       m_entity_editor;

    void create_connections();

    foundation::Dictionary get_values() const;

  private slots:
    void slot_apply();
    void slot_accept();
    void slot_cancel();
};

}       // namespace studio
}       // namespace appleseed

#endif  // !APPLESEED_STUDIO_MAINWINDOW_FALSECOLORSWINDOW_H
