<template>
  <FullCalendar 
    default-view="dayGridMonth"
    :locale="locale"
    :header="calendarHeader"
    :weekends="calendarWeekends"
    :plugins="calendarPlugins"
    :events="calendarEvents"
  /> 
</template>

<script>
  import FullCalendar from '@fullcalendar/vue'
  import dayGridPlugin from '@fullcalendar/daygrid'
  import timeGridPlugin from "@fullcalendar/timegrid";
  import interactionPlugin from "@fullcalendar/interaction";
  import jaLocale from "@fullcalendar/core/locales/ja"; // 日本語化用

  export default {
    name: 'calendar',
    components: {
      FullCalendar // make the <FullCalendar> tag available
    },
    data() {
      return {
        locale: jaLocale, // 日本語化
        // カレンダーヘッダーのデザイン
        calendarHeader: {
          left: "prev,next today",
          center: "title",
          right: "dayGridMonth,Week,Day,listWeek"
        },
        calendarWeekends: true, // 土日を表示するか
        // カレンダーで使用するプラグイン
        calendarPlugins: [dayGridPlugin, timeGridPlugin, interactionPlugin],
        // カレンダーに表示するスケジュール一覧
        calendarEvents: [
          // TODO: データベースから取ってきたやつを反映できるようにする。
          {
            title: "報告会",
            start: "2020-03-10T10:00:00",
            end: "2020-03-10T12:30:00"
          },
          {
            title: "ミーティング",
            start: "2020-03-12T10:30:00",
            end: "2020-03-12T12:30:00"
          },
          {
            title: "打ち合わせ",
            start: "2020-03-18T13:30:00",
            end: "2020-03-18T14:30:00"
          }
        ]
      }
    }
  }
</script>

<style lang='scss'>
  @import '~@fullcalendar/core/main.css';
  @import '~@fullcalendar/daygrid/main.css';
</style>