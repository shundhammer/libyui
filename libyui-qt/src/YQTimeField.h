/*---------------------------------------------------------------------\
|								       |
|		       __   __	  ____ _____ ____		       |
|		       \ \ / /_ _/ ___|_   _|___ \		       |
|			\ V / _` \___ \ | |   __) |		       |
|			 | | (_| |___) || |  / __/		       |
|			 |_|\__,_|____/ |_| |_____|		       |
|								       |
|				core system			       |
|							 (C) SuSE GmbH |
\----------------------------------------------------------------------/

  File:		YQTimeField.h

  Author:	Stefan Hundhammer <sh@suse.de>

/-*/


#ifndef YQTimeField_h
#define YQTimeField_h

#include <QFrame>
#include "YTimeField.h"

class YQWidgetCaption;
class QTimeEdit;


class YQTimeField : public QFrame, public YTimeField
{
    Q_OBJECT

public:
    /**
     * Constructor.
     **/
    YQTimeField( YWidget *	parent,
		 const string & label );

    /**
     * Destructor.
     **/
    virtual ~YQTimeField();

    /**
     * Get the current value (the text entered by the user or set from the
     * outside) of this input field.
     *
     * Implemented from YSimpleInputField.
     **/
    virtual string value();

    /**
     * Set the current value (the text entered by the user or set from the
     * outside) of this input field.
     *
     * Implemented from YSimpleInputField.
     **/
    virtual void setValue( const string & newValue );

    /**
     * Set the label (the caption above the input field).
     *
     * Reimplemented from YSimpleInputField.
     **/
    virtual void setLabel( const string & label );

    /**
     * Set enabled/disabled state.
     *
     * Reimplemented from YWidget.
     **/
    virtual void setEnabled( bool enabled );

    /**
     * Preferred width of the widget.
     *
     * Reimplemented from YWidget.
     **/
    virtual int preferredWidth();

    /**
     * Preferred height of the widget.
     *
     * Reimplemented from YWidget.
     **/
    virtual int preferredHeight();

    /**
     * Set the new size of the widget.
     *
     * Reimplemented from YWidget.
     **/
    virtual void setSize( int newWidth, int newHeight );

    /**
     * Accept the keyboard focus.
     *
     * Reimplemented from YWidget.
     **/
    virtual bool setKeyboardFocus();


protected:

    YQWidgetCaption *	_caption;
    QTimeEdit *		_qt_timeEdit;
};


#endif // YQTimeField_h