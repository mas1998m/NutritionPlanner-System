#ifndef JSON_HIGHLIGHTER_H
#define JSON_HIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QTextDocument>

class JsonHighlighter : public QSyntaxHighlighter {
    Q_OBJECT

public:
    JsonHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;
};

#endif // JSON_HIGHLIGHTER_H
