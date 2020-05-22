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
        ]
      }
    },
    methods: {
      addCalendarEvwnts(a) {
        if (confirm("新しいスケジュールを" + arg.dateStr + "に追加しますか ?")) {
          this.calendarEvents.push({
            title: "",
            start: arg.date,
            allDay: arg.allDay
          });
        }
      }
    }
  }
</script>

<style lang='scss'>
  @import '~@fullcalendar/core/main.css';
  @import '~@fullcalendar/daygrid/main.css';
</style>