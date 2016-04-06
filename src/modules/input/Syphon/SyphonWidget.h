/* Copyright (c) 2014-2015 "Omnidome" by cr8tr
 * Dome Mapping Projection Software (http://omnido.me).
 * Omnidome was created by Michael Winkelmann aka Wilston Oreo (@WilstonOreo)
 *
 * This file is part of Omnidome.
 *
 * Omnidome is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OMNI_UI_INPUT_SYPHON_H_
#define OMNI_UI_INPUT_SYPHON_H_

#include <omni/util.h>
#include <omni/ui/mixin/Locked.h>
#include <omni/ui/InputPreview.h>
#include <omni/ui/ParameterWidget.h>
#include "Syphon.h"

class QComboBox;

namespace omni {
  namespace input {
    class SyphonServerManager;
  }

    namespace ui {
        namespace input {
            class SyphonServerItemModel;

            /// Syphon widget
            class Syphon :
              public omni::ui::ParameterWidget,
              protected omni::ui::mixin::Locked {
                Q_OBJECT
            public:
                Syphon(omni::input::Syphon*, QWidget* = nullptr);
                ~Syphon();

            public slots:
                void updateServerList();

                /// Pass-through signal to update input preview
                void triggerUpdate();

            signals:
                void inputChanged();

            private slots:
                void setDescriptionToInput();
            private:
                void setup();

                omni::input::Syphon* input_ = nullptr;
                QUniquePtr<InputPreview> preview_;
                QUniquePtr<QComboBox> boxServerList_;
                QUniquePtr<SyphonServerItemModel> model_;
                std::unique_ptr<omni::input::SyphonServerManager> serverManager_;
            };
        }
    }
}


#endif /* OMNI_UI_INPUT_SYPHON_H_ */
