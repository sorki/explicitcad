/****************************************************************************
**
** Copyright (C) 2004-2006 Trolltech ASA. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** Licensees holding a valid Qt License Agreement may use this file in
** accordance with the rights, responsibilities and obligations
** contained therein.  Please consult your licensing agreement or
** contact sales@trolltech.com if any conditions of this licensing
** agreement are not clear to you.
**
** Further information about Qt licensing is available at:
** http://www.trolltech.com/products/qt/licensing.html or by
** contacting info@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QSplitter>
#include <Qsci/qscilexer.h>

#include "canvas.h"

class QAction;
class QMenu;
class QsciScintilla;
class Preferences;
class ViewWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    bool load_stl(const QString& filename, bool is_reload=false);
public slots:
    //void on_open();
    //void on_about();
    void on_bad_stl();
    void on_empty_mesh();
    void on_missing_file();
    void on_confusing_stl();

    //void enable_open();
    //void disable_open();

    void set_watched(const QString& filename);

private slots:
    //void on_projection(QAction* proj);
    //void on_drawMode(QAction* mode);
    void on_watched_change(const QString& filename);
    void on_reload();
    void on_autoreload_triggered(bool r);
    ///void on_clear_recent();
    //void on_load_recent(QAction* a);
    //void on_loaded(const QString& filename);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void openPreferences();
    void documentWasModified();
    bool exportSTL();
    void render(const QString exportname="");
    void updateLog(const QString &text);
    void logError(const QString &text);

signals:
    void newlogmsg(const QString &text);

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName, bool setname=true);
    void setCurrentFile(const QString &fileName);
    void on_render(const QString exportname="", float res=0);

    QString strippedName(const QString &fullFileName);

    QsciScintilla *textEdit;
    QsciLexer *lexer;
    ViewWidget *view;
    QSplitter* splitter;
    QSplitter* splitterR;
    QString curFile;
    QTextEdit* outputcon;
    QFileSystemWatcher* watcher;

    Preferences *preferences;

    struct Renderer {
        QProcess process;
        QTemporaryFile stl;
        enum Mode { Preview, Export } mode;
        bool reload = false;
    };

    Renderer renderer;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *prefAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *renderAct;
    QAction *exportAct;

};

#endif
