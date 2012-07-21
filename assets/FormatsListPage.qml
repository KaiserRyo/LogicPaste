import bb.cascades 1.0

Page {
    id: formatsListPage
    signal cancel()
    signal selectFormat(string format)
    titleBar: TitleBar {
        title: "Paste Formats"
        visibility: ChromeVisibility.Visible
        dismissAction: ActionItem {
            title: "Cancel"
            onTriggered: {
                formatsListPage.cancel();
            }
        }
    }
    content: Container {
        ListView {
            id: formatsList
            dataModel: XmlDataModel {
                id: formatsModel
                source: "models/paste_formats.xml"
            }
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            listItemComponents: [
                ListItemComponent {
                    type: "format"
                    StandardListItem {
                        id: formatItem
                        title: ListItemData.description
                    }
                }
            ]
            onTriggered: {
                var chosenFormat = formatsModel.data(indexPath);
                formatsListPage.selectFormat(chosenFormat.name);
            }
        }
    }
}
