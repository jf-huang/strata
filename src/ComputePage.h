////////////////////////////////////////////////////////////////////////////////
//
// This file is part of Strata.
// 
// Strata is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
// 
// Strata is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
// 
// You should have received a copy of the GNU General Public License along with
// Strata.  If not, see <http://www.gnu.org/licenses/>.
// 
// Copyright 2007 Albert Kottke
//
////////////////////////////////////////////////////////////////////////////////

#ifndef COMPUTE_PAGE_H_
#define COMPUTE_PAGE_H_

#include "SiteResponseModel.h"

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QTime>

class ComputePage : public QWidget
{
    Q_OBJECT

    public:
        ComputePage( SiteResponseModel * model, QWidget * parent = 0, Qt::WindowFlags f = 0 );

        void setModel( SiteResponseModel * model );
        
    public slots:
        void reset();
    
    protected slots:
        void started();
        void stopped();
        void cancel();

        void updateEta(int value);

    signals:
        void computing();
        void busy(bool);

        void finished();

    protected:
        SiteResponseModel * m_model;

        QProgressBar * m_progressBar;
        QLineEdit * m_etaLineEdit;

        QPushButton * m_computeButton;
        QPushButton * m_cancelButton;

        QTime m_timer;
};
#endif
