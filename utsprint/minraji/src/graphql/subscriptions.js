/* eslint-disable */
// this is an auto generated file. This will be overwritten

export const onCreateMessage = /* GraphQL */ `
  subscription OnCreateMessage {
    onCreateMessage {
      id
      username
      content
    }
  }
`;
export const onUpdateMessage = /* GraphQL */ `
  subscription OnUpdateMessage {
    onUpdateMessage {
      id
      username
      content
    }
  }
`;
export const onDeleteMessage = /* GraphQL */ `
  subscription OnDeleteMessage {
    onDeleteMessage {
      id
      username
      content
    }
  }
`;
export const onCreateUser = /* GraphQL */ `
  subscription OnCreateUser {
    onCreateUser {
      id
      username
      roomid {
        id
        movie
        tilte
        users {
          nextToken
        }
        time
        reservedtime
      }
    }
  }
`;
export const onUpdateUser = /* GraphQL */ `
  subscription OnUpdateUser {
    onUpdateUser {
      id
      username
      roomid {
        id
        movie
        tilte
        users {
          nextToken
        }
        time
        reservedtime
      }
    }
  }
`;
export const onDeleteUser = /* GraphQL */ `
  subscription OnDeleteUser {
    onDeleteUser {
      id
      username
      roomid {
        id
        movie
        tilte
        users {
          nextToken
        }
        time
        reservedtime
      }
    }
  }
`;
export const onCreateRoom = /* GraphQL */ `
  subscription OnCreateRoom {
    onCreateRoom {
      id
      movie
      tilte
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
    }
  }
`;
export const onUpdateRoom = /* GraphQL */ `
  subscription OnUpdateRoom {
    onUpdateRoom {
      id
      movie
      tilte
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
    }
  }
`;
export const onDeleteRoom = /* GraphQL */ `
  subscription OnDeleteRoom {
    onDeleteRoom {
      id
      movie
      tilte
      users {
        items {
          id
          username
        }
        nextToken
      }
      time
      reservedtime
    }
  }
`;
