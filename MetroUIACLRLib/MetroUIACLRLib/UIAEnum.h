#ifndef _UIA_ENUM_H_
#define _UIA_ENUM_H_


namespace MetroUIACLRLib{

public enum class EventID : int
{
	 UIA_ToolTipOpenedEventId	=	20000,

 UIA_ToolTipClosedEventId	=	20001,

 UIA_StructureChangedEventId	=	20002,

 UIA_MenuOpenedEventId	=	20003,

 UIA_AutomationPropertyChangedEventId	=	20004,

 UIA_AutomationFocusChangedEventId	=	20005,

 UIA_AsyncContentLoadedEventId	=	20006,

 UIA_MenuClosedEventId	=	20007,

 UIA_LayoutInvalidatedEventId	=	20008,

 UIA_Invoke_InvokedEventId	=	20009,

 UIA_SelectionItem_ElementAddedToSelectionEventId	=	20010,

 UIA_SelectionItem_ElementRemovedFromSelectionEventId	=	20011,

 UIA_SelectionItem_ElementSelectedEventId	=	20012,

 UIA_Selection_InvalidatedEventId	=	20013,

 UIA_Text_TextSelectionChangedEventId	=	20014,

 UIA_Text_TextChangedEventId	=	20015,

 UIA_Window_WindowOpenedEventId	=	20016,

 UIA_Window_WindowClosedEventId	=	20017,

 UIA_MenuModeStartEventId	=	20018,

 UIA_MenuModeEndEventId	=	20019,

 UIA_InputReachedTargetEventId	=	20020,

 UIA_InputReachedOtherElementEventId	=	20021,

 UIA_InputDiscardedEventId	=	20022,

 UIA_SystemAlertEventId	=	20023,

 UIA_LiveRegionChangedEventId	=	20024,

 UIA_HostedFragmentRootsInvalidatedEventId	=	20025,

 UIA_Drag_DragStartEventId	=	20026,

 UIA_Drag_DragCancelEventId	=	20027,

 UIA_Drag_DragCompleteEventId	=	20028,

 UIA_DropTarget_DragEnterEventId	=	20029,

 UIA_DropTarget_DragLeaveEventId	=	20030,

 UIA_DropTarget_DroppedEventId	=	20031,
};



public enum class OrientationType : int
{
};

public enum class TreeScope:int
{
	  TreeScope_Element	= 0x1,
        TreeScope_Children	= 0x2,
        TreeScope_Descendants	= 0x4,
        TreeScope_Parent	= 0x8,
        TreeScope_Ancestors	= 0x10,
        TreeScope_Subtree	= ( ( TreeScope_Element | TreeScope_Children )  | TreeScope_Descendants ) 
};

public enum class PropertyConditionFlags
{
	PropertyConditionFlags_None	= 0,
    PropertyConditionFlags_IgnoreCase	= 0x1
} ;

public enum class AutomationElementMode
{
	AutomationElementMode_None	= 0,
    AutomationElementMode_Full	= ( AutomationElementMode_None + 1 ) 
} ;

public enum class CONTROLTYPEID : int
{
};

public enum class PATTERNID : int
{
 NONE = 0,

 UIA_InvokePatternId	=	10000,

 UIA_SelectionPatternId	=	10001,

 UIA_ValuePatternId	=	10002,

 UIA_RangeValuePatternId	=	10003,

 UIA_ScrollPatternId	=	10004,

 UIA_ExpandCollapsePatternId	=	10005,

 UIA_GridPatternId	=	10006,

 UIA_GridItemPatternId	=	10007,

 UIA_MultipleViewPatternId	=	10008,

 UIA_WindowPatternId	=	10009,

 UIA_SelectionItemPatternId	=	10010,

 UIA_DockPatternId	=	10011,

 UIA_TablePatternId	=	10012,

 UIA_TableItemPatternId	=	10013,

 UIA_TextPatternId	=	10014,

 UIA_TogglePatternId	=	10015,

 UIA_TransformPatternId	=	10016,

 UIA_ScrollItemPatternId	=	10017,

 UIA_LegacyIAccessiblePatternId	=	10018,

 UIA_ItemContainerPatternId	=	10019,

 UIA_VirtualizedItemPatternId	=	10020,

 UIA_SynchronizedInputPatternId	=	10021,

 UIA_ObjectModelPatternId	=	10022,

 UIA_AnnotationPatternId	=	10023,

 UIA_TextPattern2Id	=	10024,

 UIA_StylesPatternId	=	10025,

 UIA_SpreadsheetPatternId	=	10026,

 UIA_SpreadsheetItemPatternId	=	10027,

 UIA_TransformPattern2Id	=	10028,

 UIA_TextChildPatternId	=	10029,

 UIA_DragPatternId	=	10030,

 UIA_DropTargetPatternId	=	10031,
};

public enum  class PROPERTYID
{
	 UIA_RuntimeIdPropertyId	=	30000,

 UIA_BoundingRectanglePropertyId	=	30001,

 UIA_ProcessIdPropertyId	=	30002,

 UIA_ControlTypePropertyId	=	30003,

 UIA_LocalizedControlTypePropertyId	=	30004,

 UIA_NamePropertyId	=	30005,

 UIA_AcceleratorKeyPropertyId	=	30006,

 UIA_AccessKeyPropertyId	=	30007,

 UIA_HasKeyboardFocusPropertyId	=	30008,

 UIA_IsKeyboardFocusablePropertyId	=	30009,

 UIA_IsEnabledPropertyId	=	30010,

 UIA_AutomationIdPropertyId	=	30011,

 UIA_ClassNamePropertyId	=	30012,

 UIA_HelpTextPropertyId	=	30013,

 UIA_ClickablePointPropertyId	=	30014,

 UIA_CulturePropertyId	=	30015,

 UIA_IsControlElementPropertyId	=	30016,

 UIA_IsContentElementPropertyId	=	30017,

 UIA_LabeledByPropertyId	=	30018,

 UIA_IsPasswordPropertyId	=	30019,

 UIA_NativeWindowHandlePropertyId	=	30020,

 UIA_ItemTypePropertyId	=	30021,

 UIA_IsOffscreenPropertyId	=	30022,

 UIA_OrientationPropertyId	=	30023,

 UIA_FrameworkIdPropertyId	=	30024,

 UIA_IsRequiredForFormPropertyId	=	30025,

 UIA_ItemStatusPropertyId	=	30026,

 UIA_IsDockPatternAvailablePropertyId	=	30027,

 UIA_IsExpandCollapsePatternAvailablePropertyId	=	30028,

 UIA_IsGridItemPatternAvailablePropertyId	=	30029,

 UIA_IsGridPatternAvailablePropertyId	=	30030,

 UIA_IsInvokePatternAvailablePropertyId	=	30031,

 UIA_IsMultipleViewPatternAvailablePropertyId	=	30032,

 UIA_IsRangeValuePatternAvailablePropertyId	=	30033,

 UIA_IsScrollPatternAvailablePropertyId	=	30034,

 UIA_IsScrollItemPatternAvailablePropertyId	=	30035,

 UIA_IsSelectionItemPatternAvailablePropertyId	=	30036,

 UIA_IsSelectionPatternAvailablePropertyId	=	30037,

 UIA_IsTablePatternAvailablePropertyId	=	30038,

 UIA_IsTableItemPatternAvailablePropertyId	=	30039,

 UIA_IsTextPatternAvailablePropertyId	=	30040,

 UIA_IsTogglePatternAvailablePropertyId	=	30041,

 UIA_IsTransformPatternAvailablePropertyId	=	30042,

 UIA_IsValuePatternAvailablePropertyId	=	30043,

 UIA_IsWindowPatternAvailablePropertyId	=	30044,

 UIA_ValueValuePropertyId	=	30045,

 UIA_ValueIsReadOnlyPropertyId	=	30046,

 UIA_RangeValueValuePropertyId	=	30047,

 UIA_RangeValueIsReadOnlyPropertyId	=	30048,

 UIA_RangeValueMinimumPropertyId	=	30049,

 UIA_RangeValueMaximumPropertyId	=	30050,

 UIA_RangeValueLargeChangePropertyId	=	30051,

 UIA_RangeValueSmallChangePropertyId	=	30052,

 UIA_ScrollHorizontalScrollPercentPropertyId	=	30053,

 UIA_ScrollHorizontalViewSizePropertyId	=	30054,

 UIA_ScrollVerticalScrollPercentPropertyId	=	30055,

 UIA_ScrollVerticalViewSizePropertyId	=	30056,

 UIA_ScrollHorizontallyScrollablePropertyId	=	30057,

 UIA_ScrollVerticallyScrollablePropertyId	=	30058,

 UIA_SelectionSelectionPropertyId	=	30059,

 UIA_SelectionCanSelectMultiplePropertyId	=	30060,

 UIA_SelectionIsSelectionRequiredPropertyId	=	30061,

 UIA_GridRowCountPropertyId	=	30062,

 UIA_GridColumnCountPropertyId	=	30063,

 UIA_GridItemRowPropertyId	=	30064,

 UIA_GridItemColumnPropertyId	=	30065,

 UIA_GridItemRowSpanPropertyId	=	30066,

 UIA_GridItemColumnSpanPropertyId	=	30067,

 UIA_GridItemContainingGridPropertyId	=	30068,

 UIA_DockDockPositionPropertyId	=	30069,

 UIA_ExpandCollapseExpandCollapseStatePropertyId	=	30070,

 UIA_MultipleViewCurrentViewPropertyId	=	30071,

 UIA_MultipleViewSupportedViewsPropertyId	=	30072,

 UIA_WindowCanMaximizePropertyId	=	30073,

 UIA_WindowCanMinimizePropertyId	=	30074,

 UIA_WindowWindowVisualStatePropertyId	=	30075,

 UIA_WindowWindowInteractionStatePropertyId	=	30076,

 UIA_WindowIsModalPropertyId	=	30077,

 UIA_WindowIsTopmostPropertyId	=	30078,

 UIA_SelectionItemIsSelectedPropertyId	=	30079,

 UIA_SelectionItemSelectionContainerPropertyId	=	30080,

 UIA_TableRowHeadersPropertyId	=	30081,

 UIA_TableColumnHeadersPropertyId	=	30082,

 UIA_TableRowOrColumnMajorPropertyId	=	30083,

 UIA_TableItemRowHeaderItemsPropertyId	=	30084,

 UIA_TableItemColumnHeaderItemsPropertyId	=	30085,

 UIA_ToggleToggleStatePropertyId	=	30086,

 UIA_TransformCanMovePropertyId	=	30087,

 UIA_TransformCanResizePropertyId	=	30088,

 UIA_TransformCanRotatePropertyId	=	30089,

 UIA_IsLegacyIAccessiblePatternAvailablePropertyId	=	30090,

 UIA_LegacyIAccessibleChildIdPropertyId	=	30091,

 UIA_LegacyIAccessibleNamePropertyId	=	30092,

 UIA_LegacyIAccessibleValuePropertyId	=	30093,

 UIA_LegacyIAccessibleDescriptionPropertyId	=	30094,

 UIA_LegacyIAccessibleRolePropertyId	=	30095,

 UIA_LegacyIAccessibleStatePropertyId	=	30096,

 UIA_LegacyIAccessibleHelpPropertyId	=	30097,

 UIA_LegacyIAccessibleKeyboardShortcutPropertyId	=	30098,

 UIA_LegacyIAccessibleSelectionPropertyId	=	30099,

 UIA_LegacyIAccessibleDefaultActionPropertyId	=	30100,

 UIA_AriaRolePropertyId	=	30101,

 UIA_AriaPropertiesPropertyId	=	30102,

 UIA_IsDataValidForFormPropertyId	=	30103,

 UIA_ControllerForPropertyId	=	30104,

 UIA_DescribedByPropertyId	=	30105,

 UIA_FlowsToPropertyId	=	30106,

 UIA_ProviderDescriptionPropertyId	=	30107,

 UIA_IsItemContainerPatternAvailablePropertyId	=	30108,

 UIA_IsVirtualizedItemPatternAvailablePropertyId	=	30109,

 UIA_IsSynchronizedInputPatternAvailablePropertyId	=	30110,

 UIA_OptimizeForVisualContentPropertyId	=	30111,

 UIA_IsObjectModelPatternAvailablePropertyId	=	30112,

 UIA_AnnotationAnnotationTypeIdPropertyId	=	30113,

 UIA_AnnotationAnnotationTypeNamePropertyId	=	30114,

 UIA_AnnotationAuthorPropertyId	=	30115,

 UIA_AnnotationDateTimePropertyId	=	30116,

 UIA_AnnotationTargetPropertyId	=	30117,

 UIA_IsAnnotationPatternAvailablePropertyId	=	30118,

 UIA_IsTextPattern2AvailablePropertyId	=	30119,

 UIA_StylesStyleIdPropertyId	=	30120,

 UIA_StylesStyleNamePropertyId	=	30121,

 UIA_StylesFillColorPropertyId	=	30122,

 UIA_StylesFillPatternStylePropertyId	=	30123,

 UIA_StylesShapePropertyId	=	30124,

 UIA_StylesFillPatternColorPropertyId	=	30125,

 UIA_StylesExtendedPropertiesPropertyId	=	30126,

 UIA_IsStylesPatternAvailablePropertyId	=	30127,

 UIA_IsSpreadsheetPatternAvailablePropertyId	=	30128,

 UIA_SpreadsheetItemFormulaPropertyId	=	30129,

 UIA_SpreadsheetItemAnnotationObjectsPropertyId	=	30130,

 UIA_SpreadsheetItemAnnotationTypesPropertyId	=	30131,

 UIA_IsSpreadsheetItemPatternAvailablePropertyId	=	30132,

 UIA_Transform2CanZoomPropertyId	=	30133,

 UIA_IsTransformPattern2AvailablePropertyId	=	30134,

 UIA_LiveSettingPropertyId	=	30135,

 UIA_IsTextChildPatternAvailablePropertyId	=	30136,

 UIA_IsDragPatternAvailablePropertyId	=	30137,

 UIA_DragIsGrabbedPropertyId	=	30138,

 UIA_DragDropEffectPropertyId	=	30139,

 UIA_DragDropEffectsPropertyId	=	30140,

 UIA_IsDropTargetPatternAvailablePropertyId	=	30141,

 UIA_DropTargetDropTargetEffectPropertyId	=	30142,

 UIA_DropTargetDropTargetEffectsPropertyId	=	30143,

 UIA_DragGrabbedItemsPropertyId	=	30144,

 UIA_Transform2ZoomLevelPropertyId	=	30145,

 UIA_Transform2ZoomMinimumPropertyId	=	30146,

 UIA_Transform2ZoomMaximumPropertyId	=	30147,

 UIA_FlowsFromPropertyId	=	30148,
};

public enum class TextAttributeID
{
	 UIA_AnimationStyleAttributeId	=	40000,

 UIA_BackgroundColorAttributeId	=	40001,

 UIA_BulletStyleAttributeId	=	40002,

 UIA_CapStyleAttributeId	=	40003,

 UIA_CultureAttributeId	=	40004,

 UIA_FontNameAttributeId	=	40005,

 UIA_FontSizeAttributeId	=	40006,

 UIA_FontWeightAttributeId	=	40007,

 UIA_ForegroundColorAttributeId	=	40008,

 UIA_HorizontalTextAlignmentAttributeId	=	40009,

 UIA_IndentationFirstLineAttributeId	=	40010,

 UIA_IndentationLeadingAttributeId	=	40011,

 UIA_IndentationTrailingAttributeId	=	40012,

 UIA_IsHiddenAttributeId	=	40013,

 UIA_IsItalicAttributeId	=	40014,

 UIA_IsReadOnlyAttributeId	=	40015,

 UIA_IsSubscriptAttributeId	=	40016,

 UIA_IsSuperscriptAttributeId	=	40017,

 UIA_MarginBottomAttributeId	=	40018,

 UIA_MarginLeadingAttributeId	=	40019,

 UIA_MarginTopAttributeId	=	40020,

 UIA_MarginTrailingAttributeId	=	40021,

 UIA_OutlineStylesAttributeId	=	40022,

 UIA_OverlineColorAttributeId	=	40023,

 UIA_OverlineStyleAttributeId	=	40024,

 UIA_StrikethroughColorAttributeId	=	40025,

 UIA_StrikethroughStyleAttributeId	=	40026,

 UIA_TabsAttributeId	=	40027,

 UIA_TextFlowDirectionsAttributeId	=	40028,

 UIA_UnderlineColorAttributeId	=	40029,

 UIA_UnderlineStyleAttributeId	=	40030,

 UIA_AnnotationTypesAttributeId	=	40031,

 UIA_AnnotationObjectsAttributeId	=	40032,

 UIA_StyleNameAttributeId	=	40033,

 UIA_StyleIdAttributeId	=	40034,

 UIA_LinkAttributeId	=	40035,

 UIA_IsActiveAttributeId	=	40036,

 UIA_SelectionActiveEndAttributeId	=	40037,

 UIA_CaretPositionAttributeId	=	40038,

 UIA_CaretBidiModeAttributeId	=	40039,
};

};

#endif