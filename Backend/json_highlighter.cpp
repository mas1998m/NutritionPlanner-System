#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QTextDocument>
#include "json_highlighter.h"




JsonHighlighter::JsonHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    // Define the format for JSON keys
    QTextCharFormat keyFormat;
    keyFormat.setForeground(QColor("#9CDCFE"));  // Blue color for keys
    highlightingRules.append({QRegularExpression("\"([^\"\\\\]*(\\\\.[^\"\\\\]*)*)\"\\s*:"), keyFormat});


    // Define the format for JSON strings
    QTextCharFormat stringFormat;
    stringFormat.setForeground(QColor("#CE9178"));  // Orange color for strings
    highlightingRules.append({QRegularExpression("\"([^\"\\\\]*(\\\\.[^\"\\\\]*)*)\""), stringFormat});

    // Define the format for JSON numbers
    QTextCharFormat numberFormat;
    numberFormat.setForeground(QColor("#B5CEA8"));  // Green color for numbers
    highlightingRules.append({QRegularExpression("\\b\\d+(\\.\\d+)?\\b"), numberFormat});

    // Define the format for JSON booleans and null
    QTextCharFormat booleanFormat;
    booleanFormat.setForeground(QColor("#569CD6"));  // Blue color for true, false, null
    highlightingRules.append({QRegularExpression("\\b(true|false|null)\\b"), booleanFormat});

    // Define the format for JSON braces and brackets
    QTextCharFormat braceFormat;
    braceFormat.setForeground(QColor("#DCDCAA"));  // Yellow color for braces and brackets
    highlightingRules.append({QRegularExpression("[\\{\\}\\[\\]]"), braceFormat});
}

void JsonHighlighter::highlightBlock(const QString &text){
    for (const HighlightingRule &rule : highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}

