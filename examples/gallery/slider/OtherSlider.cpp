/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the 3-clause BSD License
 *****************************************************************************/

#include "OtherSlider.h"

#include <QskAspect.h>
#include <QskRgbValue.h>
#include <QskBoxShapeMetrics.h>
#include <QskBoxBorderMetrics.h>
#include <QskBoxBorderColors.h>

#include <cmath>

OtherSlider::OtherSlider( QQuickItem* parentItem )
    : QskSlider( parentItem )
{
    using namespace QskAspect;
    using namespace QskRgb;

    const qreal h = 30;
    const qreal w = 2.0 * h;
    const qreal paddingW = 0.5 * w + 1;

    // Panel

    for ( auto placement : { Horizontal, Vertical } )
    {
        const Aspect aspect = Panel | placement;

        setMetric( aspect | Size, h );
        setBoxShapeHint( aspect, 4 );
        setBoxBorderMetricsHint( aspect, 1 );
        setBoxBorderColorsHint( aspect, Grey900 );
        setGradientHint( aspect, Grey400 );

        if ( placement == Horizontal )
            setMarginsHint( aspect | Padding, QMarginsF( paddingW, 0, paddingW, 0 ) );
        else
            setMarginsHint( aspect | Padding, QMarginsF( 0, paddingW, 0, paddingW ) );
    }

    // Groove

    for ( auto placement : { Horizontal, Vertical } )
    {
        const Aspect aspect = Groove | placement;

        setMetric( aspect | Size, 4 );
        setBoxBorderMetricsHint( aspect, 0 );
        setBoxShapeHint( aspect, 1 );

        setGradientHint( aspect, Qt::black );
    }

    // no Fill
    for ( auto placement : { Horizontal, Vertical } )
    {
        const Aspect aspect = Fill | placement;
        setMetric( aspect | Size, 0 );
    }

    // Handle

    for ( auto placement : { Horizontal, Vertical } )
    {
        const Aspect aspect = Handle | placement;

        setBoxBorderMetricsHint( aspect, 1 );
        setBoxShapeHint( aspect, 4 );

        const qreal m = 0.5 * std::ceil( 0.5 * ( w - h ) ) + 1;

        if ( placement == Horizontal )
            setMarginsHint( aspect | Margin, QMarginsF( -m, 0, -m, 0 ) );
        else
            setMarginsHint( aspect | Margin, QMarginsF( 0, -m, 0, -m ) );

        for ( auto state : { NoState, Pressed } )
        {
            setBoxBorderColorsHint( aspect | state, Grey600 );
            setGradientHint( aspect | state, Blue400 );
        }
    }
}
